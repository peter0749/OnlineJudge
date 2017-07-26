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
    const int MaxFastBits = 16;
    int **gFFTBitTable = 0;

    int NumberOfBitsNeeded(int PowerOfTwo) {
        for (int i = 0;; ++i) {
            if (PowerOfTwo & (1 << i)) {
                return i;
            }
        }
    }

    int ReverseBits(int index, int NumBits) {
        int ret = 0;
        for (int i = 0; i < NumBits; ++i, index >>= 1) {
            ret = (ret << 1) | (index & 1);
        }
        return ret;
    }

    void InitFFT() {
        gFFTBitTable = new int *[MaxFastBits];
        for (int i = 1, length = 2; i <= MaxFastBits; ++i, length <<= 1) {
            gFFTBitTable[i - 1] = new int[length];
            for (int j = 0; j < length; ++j) {
                gFFTBitTable[i - 1][j] = ReverseBits(j, i);
            }
        }
    }
    inline int FastReverseBits(int i, int NumBits) {
        return NumBits <= MaxFastBits ? gFFTBitTable[NumBits - 1][i] : ReverseBits(i, NumBits);
    }

    void FFT(bool InverseTransform, vector<complex<double> >& In, vector<complex<double> >& Out) {
        if (!gFFTBitTable) { InitFFT(); }
        // simultaneous data copy and bit-reversal ordering into outputs
        int NumSamples = In.size();
        int NumBits = NumberOfBitsNeeded(NumSamples);
        for (int i = 0; i < NumSamples; ++i) {
            Out[FastReverseBits(i, NumBits)] = In[i];
        }
        // the FFT process
        double angle_numerator = acos(-1.) * (InverseTransform ? -2 : 2);
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

    vector<double> convolution(vector<double> a, vector<double> b) {
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
        vector<double> ret(n);
        for (int i = 0; i < n; ++i) {
            ret[i] = s[i].real();
        }
        return ret;
    }
};

const size_t MAXN=1<<18;
uint8_t a[MAXN], b[MAXN];

int main(void) {
    using namespace std;
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    const double eps=1.5e-1;
    string sa, sb;
    while(cin>>sa>>sb) {
        memset(a,0x00,sizeof(a));
        memset(b,0x00,sizeof(b));
        int maxN = sa.length()+sb.length();
        int digitN = 1;
        for (; maxN>digitN; digitN<<=1);
        for (int i=0; i<sa.length(); ++i) {
            a[i] = sa[ sa.length()-1-i ]-'0';
        }
        for (int i=digitN-sb.length(), j=0; j<sb.length(); ++i, ++j) {
            b[i] = sb[j]-'0';
        }
        vector<double> res = FFT::convolution(vector<double>(a,a+digitN), vector<double>(b,b+digitN));
        vector<long long> res2((size_t)maxN, 0);
        for (int i=1; i<=maxN; ++i) {
            res2[i-1] = ((long long)floor(res[i]+eps));
        }
        res.clear();
        for (int i=0; i<maxN; ++i) {
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