#pragma GCC target ("avx")
#pragma GCC optimize ("Os")
#pragma GCC optimize ("O3")
#include <iostream>
#include <algorithm>
#include <vector>
#include <complex>
#include <cmath>
#include <cstring>
#include <cstdint>
#define for if (0); else for

namespace FFT  // WARNING!!! do not reveal this namespace
{
    using namespace std; // be careful
#ifdef M_PIl
#undef M_PIl
#endif
#define M_PIl 3.1415926535897932384626433832795028841971693993751058209749445923078164062862089986280348253421170679

    int NumberOfBitsNeeded(int PowerOfTwo) {
        for (int i = 0;; ++i) {
            if (PowerOfTwo & (1 << i)) {
                return i;
            }
        }
    }

    inline uint32_t FastReverseBits(uint32_t a, int NumBits) {
        a = ( ( a & 0x55555555U ) << 1 ) | ( ( a & 0xAAAAAAAAU ) >> 1 ) ;
        a = ( ( a & 0x33333333U ) << 2 ) | ( ( a & 0xCCCCCCCCU ) >> 2 ) ;
        a = ( ( a & 0x0F0F0F0FU ) << 4 ) | ( ( a & 0xF0F0F0F0U ) >> 4 ) ;
        a = ( ( a & 0x00FF00FFU ) << 8 ) | ( ( a & 0xFF00FF00U ) >> 8 ) ;
        a = ( ( a & 0x0000FFFFU ) << 16 ) | ( ( a & 0xFFFF0000U ) >> 16 ) ;
        return a >> (32 - NumBits);
    }

    void FFT(bool, const vector<complex<double> >&, vector<complex<double> >&) __attribute__((optimize("fast-math")));
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
            double delta_angle = angle_numerator / BlockSize;
            double sin1 = sin(-delta_angle);
            double cos1 = cos(-delta_angle);
            double sin2 = sin(-delta_angle * 2);
            double cos2 = cos(-delta_angle * 2);
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

    template<class T>
    void convolution(const vector<T> &a, const vector<T> &b, vector<double> &ret) __attribute__((optimize("fast-math")));
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
};

int main(void) {
    using namespace std;
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    const double eps=1.5e-1;
    string sa, sb;
    vector<uint8_t>a, b;
    vector<double> res;
    vector<long long> res2;
    while(cin>>sa>>sb) {
        int maxN = sa.length()+sb.length();
        int digitN = 1;
        for (; maxN>digitN; digitN<<=1);
        a.resize(digitN,0);
        b.resize(digitN,0);
        for (int i=0; i<sa.length(); ++i) {
            a[i] = sa[ sa.length()-1-i ]-'0';
        }
        for (int i=digitN-sb.length(), j=0; j<sb.length(); ++i, ++j) {
            b[i] = sb[j]-'0';
        }
        FFT::convolution<uint8_t>(a, b, res);
        a.clear(), b.clear();
        res2.resize(digitN, 0);
        for (int i=1; i<=maxN; ++i) {
            res2[i-1] = ((long long)floor(res[i]+eps));
        }
        res.clear();
        for (int i=0; i<maxN-1; ++i) {
            res2[i+1] += res2[i]/10LL;
            res2[i  ] %= 10LL; 
        }
        bool detected=false;
        for (int i=maxN-1; i>=0; --i) {
            if (res2[i]>0LL) detected=true;
            if (detected) cout << res2[i];
        }
        if (!detected) cout << '0';
        cout << endl;
        res2.clear();
    }
    return 0;
}