#pragma GCC optimize ("Os")
#pragma GCC optimize ("O3")
#include <iostream>
#include <algorithm>
#include <vector>
#include <complex>
#include <cmath>
#include <cstring>
//#include <cstdint>

// 確認有 uint32 這個 type
#ifndef uint32_t
#define uint32_t unsigned long int
#endif

namespace FFT  // WARNING!!! do not reveal this namespace
{
    using namespace std; // be careful
    const long double M_PIl = acos(-1.);
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
    void FFT(bool, const vector<complex<long double> >&, vector<complex<long double> >&) __attribute__((optimize("fast-math")));
    // FFT 本體， In 是輸入的向量（訊號），Out 是輸出的向量（訊號）
    // 這裏其實不太重要，主要會用得的部分是下方的卷積
    // NOTE:::::::::::: 兩個向量長度必須是 2^k，等長
    void FFT(bool InverseTransform, const vector<complex<long double> >& In, vector<complex<long double> >& Out) {
        // simultaneous data copy and bit-reversal ordering into outputs
        int NumSamples = In.size();
        int NumBits = NumberOfBitsNeeded(NumSamples);
        for (int i = 0; i < NumSamples; ++i) {
            Out[FastReverseBits((uint32_t)i, NumBits)] = In[i];
        }
        // the FFT process
        long double angle_numerator = M_PIl * (InverseTransform ? -2 : 2);
        for (int BlockEnd = 1, BlockSize = 2; BlockSize <= NumSamples; BlockSize <<= 1) {
            long double ndelta_angle = -(angle_numerator / BlockSize);
            long double sin1 = sin(ndelta_angle);
            long double cos1 = cos(ndelta_angle);
            long double sin2 = sin(ndelta_angle*2); // 注意：用合角公式計算有可能放大誤差，這裡改用較保險的做法
            long double cos2 = cos(ndelta_angle*2);
            for (int i = 0; i < NumSamples; i += BlockSize) {
                complex<long double> a1(cos1, sin1), a2(cos2, sin2);
                for (int j = i, n = 0; n < BlockEnd; ++j, ++n) {
                    complex<long double> a0(2 * cos1 * a1.real() - a2.real(), 2 * cos1 * a1.imag() - a2.imag());
                    a2 = a1;
                    a1 = a0;
                    complex<long double> a = a0 * Out[j + BlockEnd];
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

    // 卷積，輸入"""等長"""的 a, b 兩向量（長度必須是 2^k），會得到 a * b （a卷積b）的結果
    // 下面的流程 A*B -> a=FFT(A); b=FFT(B) -> c = a dot b -> ANS = IFFT(c)
    template<class T> // a, b 兩向量的輸入型態
        void convolution(const vector<T> &a, vector<T> &ret) {
            int n = a.size();
            vector<complex<long double> > s(n), d(n), y(n);
            for (int i = 0; i < n; ++i) {
                s[i] = complex<long double>((long double)a[i], 0);
            }
            FFT(false, s, d); // d1 = FFT(a)
            for (int i = 0; i < n; ++i) { // y = d1 dot d2
                y[i] = d[i] * d[i];
            }
            FFT(true, y, s);   // ANS = IFFT(y)
            ret.resize(n,0);
            for (int i = 0; i < n; ++i) { 
                ret[i] = (s[i].real()+0.5L);
            }
        }
}; // namespace FFT

#include <iostream>
#include <iomanip>
using namespace std;
vector<int>input;
vector<long long>num;
vector<long long>res;

int main(void) {
    int T;
    scanf("%d", &T);
    while(T--) {
        int n;
        scanf("%d",&n);
        input.resize(n);
        for (int i=0; i<n; ++i) {
            int t;
            scanf("%d", &input[i]);
        }
        sort(input.begin(), input.end());
        int d=2; for (; (input[input.size()-1]+1)*2>d; d<<=1);
        num.resize(d,0);
        fill(num.begin(), num.end(), 0);
        for (int i=0; i<input.size(); ++i) ++num[ input[i] ];
        FFT::convolution<long long>(num,res);
        num.clear();
        for (int i=0; i<n; ++i) --res[ input[i]+input[i] ];
        for (int i=0; i<res.size(); ++i) res[i]/=2LL;
        res[0]=0LL;
        for (int i=1; i<res.size(); ++i) res[i]+=res[i-1];
        double cnt = 0;
        for (int i=0; i<n; ++i) {
            cnt += res[res.size()-1]-res[input[i]];
            cnt -= n-1;
            cnt -= (double)i*(n-1-i);
            cnt -= (double)(n-1-i)*(n-2-i)/2;
        }
        double ans = 6.0*cnt/n/(n-1.0)/(n-2.0);
        printf("%.7lf\n", ans);
        input.clear(); num.clear(); 
    }
    return 0;
}
