// 4041158, AC, 100ms, 22832k
// #pragma GCC target ("avx")
// 要確認 Judge 有支援這一個指令集，才可以開
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

// 確認有 uint32 這個 type
#ifndef uint32_t
#define uint32_t unsigned long int
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
    template<class T> // a, b 兩向量的輸入型態
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

double area[512][512];

int main(void) {
    using namespace std;
    int Ah, Aw, Bh, Bw;
    int W, H;
    vector<int> A(262144);
    vector<int> B(262144);
    vector<double> conv(262144);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int T; cin >> T;
    while (T--) {
        cin >> Ah >> Aw >> Bh >> Bw;
        W = max(Aw,Bw);
        H = max(Ah,Bh);
        int n = H*W, n2base=1;
        for (n2base=1; n>n2base; n2base<<=1); // n2base==2^k , n2base>=n
        A.resize(n2base); B.resize(n2base);
        fill(A.begin(), A.end(), 0);
        fill(B.begin(), B.end(), 0);
        for (int i=0; i<Ah; ++i) {
            for (int j=0; j<Aw; ++j) {
                cin >> A.at(i*W+j);
            }
        }
        for (int i=0; i<Bh; ++i) {
            for (int j=0; j<Bw; ++j) {
                cin >> B.at(i*W+j);
            }
        }
        FFT::convolution<int>(A, B, conv);
#ifdef DEBUG
        for (int i=0; i<conv.size(); ++i) {
            int _i=i/W;
            int _j=i%W;
            if (_i+Bh>Ah||_j+Bw>Aw) continue;
            cout << "conv[" << (i/W) << "][" << (i%W) << "] = " << conv.at(i) << endl;
        }
#endif
        memset(area, 0x00, sizeof(area));
        for (int i=1; i<=Ah; ++i) {
            double sum=0.0;
            for (int j=1; j<=Aw; ++j) {
                sum += A[(i-1)*W+(j-1)]*A[(i-1)*W+(j-1)];
                area[i][j] = sum + area[i-1][j]; // 2D prefix sum
            }
        }
        double minval=1e300;
        int x=0, y=0;
        for (int i=0; i+Bh<=Ah; ++i) {
            for (int j=0; j+Bw<=Aw; ++j) {
                double diff=area[i+Bh][j+Bw] - area[i+Bh][j] - area[i][j+Bw] + area[i][j];
#ifdef DEBUG
                cout << "A2[" << i << "][" << j << "] = " << diff << endl;
#endif
                diff -= 2.0*conv[i*W+j];
                if (diff<minval) {
                    minval = diff;
                    x=j, y=i;
                }
            }
        }
        cout << y+1 << ' ' << x+1 << endl;
    }
    return 0;
}
