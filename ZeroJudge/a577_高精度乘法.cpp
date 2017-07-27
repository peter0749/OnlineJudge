#pragma GCC target ("avx2")
#pragma GCC optimize ("Os")
#pragma GCC optimize ("O3")
#include <iostream>
#include <algorithm>
#include <vector>
#include <complex>
#include <cmath>
#include <cstring>
#include <cstdint>
#ifdef M_PIl
#undef M_PIl
#endif
// PI 常數，也可以使用 acos(-1.) 啦
#define M_PIl 3.1415926535897932384626433832795028841971693993751058209749445923078164062862089986280348253421170679
// 預防 for(int i; ...) 的 i 跑到 scope 外面
#define for if (0); else for

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
        void convolution(const vector<T> &a, const vector<T> &b, vector<double> &ret) __attribute__((optimize("fast-math")));
    // 卷積，輸入"""等長"""的 a, b 兩向量（長度必須是 2^k），會得到 a * b （a卷積b）的結果
    // 下面套用 ZOJ 上的例子:
    /**
     * Given two sequences {a1, a2, a3.. an} and {b1, b2, b3... bn},
     * their repeat convolution means:
     * r1 = a1*b1 + a2*b2 + a3*b3 + ... + an*bn
     * r2 = a1*bn + a2*b1 + a3*b2 + ... + an*bn-1
     * r3 = a1*bn-1 + a2*bn + a3*b1 + ... + an*bn-2
     * ...
     * rn = a1*b2 + a2*b3 + a3*b4 + ... + an-1*bn + an*b1
     * Notice n >= 2 and n must be power of 2.
     */
    template<class T>
        void convolution(const vector<T> &a, const vector<T> &b, vector<double> &ret) {
            int n = a.size();
            vector<complex<double> > s(n), d1(n), d2(n), y(n);
            for (int i = 0; i < n; ++i) {
                s[i] = complex<double>(a[i], 0);
            }
            FFT(false, s, d1);
            s[0] = complex<double>(b[0], 0);
            for (int i = 1; i < n; ++i) {
                s[i] = complex<double>(b[n - i], 0);
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

char sa[1<<17+10], sb[1<<17+10];

int main(void) {
    using namespace std;
    const double eps=1.5e-1;
    vector<uint8_t>a, b;
    vector<double> res;
    vector<uint32_t> res2;
    while(scanf("%s %s",sa,sb)==2) {
        int sa_length=strlen(sa);
        int sb_length=strlen(sb);
        int maxN = sa_length+sb_length;
        // 例：123*456
        // a = [3 2 1 0 0 0]
        // b = [0 0 0 4 5 6]
        // 因此卷積後的 r0 都會是 0
        int digitN = 1;
        for (; maxN>digitN; digitN<<=1);
        a.resize(digitN,0);
        b.resize(digitN,0);
        for (int i=0; i<sa_length; ++i) {
            a[i] = sa[ sa_length-1-i ]-'0';
        }
        for (int i=digitN-sb_length, j=0; j<sb_length; ++i, ++j) {
            b[i] = sb[j]-'0';
        }
        FFT::convolution<uint8_t>(a, b, res);
        a.clear(), b.clear();
        res2.resize(digitN, 0);
        int d = min((int)res.size()-1, (int)maxN);
        for (int i=1; i<=d; ++i) {
            res2[i-1] = ((uint32_t)floor(res[i]+eps));
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
