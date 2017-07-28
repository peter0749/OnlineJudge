//#pragma GCC target ("avx")
#pragma GCC optimize ("Os")
#pragma GCC optimize ("O3")
#include <iostream>
#include <algorithm>
#include <vector>
#include <complex>
#include <cmath>
#include <cstring>
//#include <cstdint>
#ifdef M_PIl
#undef M_PIl
#endif
// PI 常數，也可以使用 acos(-1.) 啦
#define M_PIl 3.1415926535897932384626433832795028841971693993751058209749445923078164062862089986280348253421170679
// 預防 for(int i; ...) 的 i 跑到 scope 外面
#define for if (0); else for

#ifndef uint32_t
#define uint32_t unsigned long int
#endif

#ifndef uint8_t
#define uint8_t unsigned char
#endif

namespace FFT  // WARNING!!! do not reveal this namespace
{
    using namespace std; // be careful

    int NumberOfBitsNeeded(int PowerOfTwo) {
        for (int i = 0;; ++i) {
            if (PowerOfTwo & (1 << i)) {
                return i;
            }
        }
    }

    // 參考 morris + 掛長 的 blog 的快速翻轉 bit (MSB->LSB; LSB->MSB)
    inline uint32_t FastReverseBits(uint32_t a, int NumBits) {
        a = ( ( a & 0x55555555U ) << 1 ) | ( ( a & 0xAAAAAAAAU ) >> 1 ) ;
        a = ( ( a & 0x33333333U ) << 2 ) | ( ( a & 0xCCCCCCCCU ) >> 2 ) ;
        a = ( ( a & 0x0F0F0F0FU ) << 4 ) | ( ( a & 0xF0F0F0F0U ) >> 4 ) ;
        a = ( ( a & 0x00FF00FFU ) << 8 ) | ( ( a & 0xFF00FF00U ) >> 8 ) ;
        a = ( ( a & 0x0000FFFFU ) << 16 ) | ( ( a & 0xFFFF0000U ) >> 16 ) ;
        return a >> (32 - NumBits);
    }

    // 嘗試打開 fast-math 優化選項，如果 Judge 機不支援，請記得把這行註解掉
    void FFT(bool, const vector<complex<double> >&, vector<complex<double> >&) __attribute__((optimize("fast-math")));
    // FFT 本體， In 是輸入的向量（訊號），Out 是輸出的向量（訊號）
    // 這裏其實不太重要，主要會用得的部分是下方的卷積
    // NOTE:::::::::::: 兩個向量長度必須是 2^k，等長
    void FFT(bool InverseTransform, const vector<complex<double> >& In, vector<complex<double> >& Out) {
        // simultaneous data copy and bit-reversal ordering into outputs
        int NumSamples = In.size();
        int NumBits = NumberOfBitsNeeded(NumSamples);
        for (int i = 0; i < NumSamples; ++i) {
            Out[FastReverseBits((uint32_t)i, NumBits)] = In[i];
        }
        // the FFT process
        double angle_numerator = M_PIl * (InverseTransform ? -2 : 2);
        for (int BlockEnd = 1, BlockSize = 2; BlockSize <= NumSamples; BlockSize <<= 1) {
            double ndelta_angle = -(angle_numerator / BlockSize);
            double sin1 = sin(ndelta_angle);
            double cos1 = cos(ndelta_angle);
            double sin2 = 2*sin1*cos1;
            double cos2 = 2*cos1*cos1-1.0;
            for (int i = 0; i < NumSamples; i += BlockSize) {
                complex<double> a1(cos1, sin1), a2(cos2, sin2);
                for (int j = i, n = 0; n < BlockEnd; ++j, ++n) {
                    complex<double> a0(2 * cos1 * a1.real() - a2.real(), 2 * cos1 * a1.imag() - a2.imag());
                    a2 = a1;
                    a1 = a0;
                    complex<double> a = a0 * Out[j + BlockEnd];
                    Out[j + BlockEnd] = Out[j] - a;
                    Out[j] += a;
                }
            }
            BlockEnd = BlockSize;
        }
        // normalize if inverse transform
        if (InverseTransform) {
            for (int i = 0; i < NumSamples; ++i) {
                Out[i] /= NumSamples;
            }
        }
    }

    // 同上，如果編譯器不支援 fast-math 選項，記得註解掉下面兩行
    template<class T>
        void mul(const vector<T> &a, const vector<T> &b, vector<double> &ret) __attribute__((optimize("fast-math")));
    // 下面的流程 A*B -> a=FFT(A); b=FFT(B) -> c = a dot b -> ANS = IFFT(c)
    template<class T>
        void mul(const vector<T> &a, const vector<T> &b, vector<double> &ret) {
            int n = a.size();
            vector<complex<double> > s(n), d1(n), d2(n), y(n);
            for (int i = 0; i < n; ++i) {
                s[i] = complex<double>(a[i], 0);
            }
            FFT(false, s, d1);
            for (int i = 0; i < n; ++i) {
                s[i] = complex<double>(b[i], 0);
            }
            FFT(false, s, d2);
            for (int i = 0; i < n; ++i) {
                y[i] = d1[i] * d2[i];
            }
            FFT(true, y, s);
            ret.resize(n,0);
            for (int i = 0; i < n; ++i) {
                ret[i] = s[i].real();
            }
        }
}; // namespace FFT

char sa[51000], sb[51000];

int main(void) {
    using namespace std;
    const double eps=1.5e-1;
    vector<uint8_t>a, b;
    vector<double> res;
    vector<uint32_t> res2;
    while(scanf("%s%s",sa,sb)==2) {
        int sa_length=strlen(sa);
        int sb_length=strlen(sb);
        int maxN = sa_length+sb_length;
        // 例：123*456
        // a = [3 2 1 0 0 0]
        // b = [6 5 4 0 0 0]
        // a*b = IFFT(FFT(A) dot FFT(B))
        int digitN = 1;
        for (; maxN>digitN; digitN<<=1);
        a.resize(digitN,0);
        b.resize(digitN,0);
        for (int i=0; i<sa_length; ++i) {
            a[i] = sa[ sa_length-1-i ]-'0';
        }
        for (int i=0; i<sb_length; ++i) {
            b[i] = sb[ sb_length-1-i ]-'0';
        }
        FFT::mul<uint8_t>(a, b, res);
        //for (const auto &v:res) cout<<v<<endl;
        a.clear(), b.clear();
        res2.resize(digitN, 0);
        for (int i=0; i<digitN; ++i) {
            res2[i] = ((uint32_t)floor(res[i]+eps));
        }
        res.clear();
        for (int i=0; i<maxN-1; ++i) {
            res2[i+1] += res2[i]/10;
            res2[i  ] %= 10;
        }
        bool detected=false;
        for (int i=maxN-1; i>=0; --i) {
            if (res2[i]>0) detected=true;
            if (detected) printf("%u",res2[i]);
        }
        if (!detected) putchar('0');
        puts("");
        res2.clear();
    }
    return 0;
}
/*
in:
0
5

11
12
out:
0
132
*/
