#pragma GCC optimize ("O3")
#pragma GCC target ("avx")
#define _DEBUG
#include <iostream>
#include <algorithm>
#include <vector>
#include <complex>
#include <cmath>
#include <cstring>
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

double area[512][512];
int A[300000];
int B[300000];
int Ah, Aw, Bh, Bw;
int W, H;

int main(void) {
    using namespace std;
    while (cin >> Ah >> Aw >> Bh >> Bw) {
        memset(A, 0x00, sizeof(A));
        memset(B, 0x00, sizeof(B));
        W = max(Aw,Bw);
        H = max(Ah,Bh);
        for (int i=0; i<Ah; ++i) {
            for (int j=0; j<Aw; ++j) {
                cin >> A[i*W+j];
            }
        }
        for (int i=0; i<Bh; ++i) {
            for (int j=0; j<Bw; ++j) {
                cin >> B[i*W+j];
            }
        }
        int n = H*W, n2base=1;
        for (n2base=1; n>n2base; n2base<<=1); // n2base==2^k , n2base>=n
        vector<double> conv( \
                FFT::convolution(vector<double>(A, A+n2base), vector<double>(B, B+n2base)) \
                );
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
