#pragma GCC target ("avx2")
#pragma GCC optimize ("O3")
#include <algorithm>
#include <iostream>
#include <cmath>
#include <cstdio>
#include <cstring>
using namespace std;

namespace FFT_TOOL {
    // 若常數 long double M_PIl 沒有定義，自行定義一個常數
#ifndef M_PIl
    const long double M_PIl = std::acos(-1.0L);
#endif
    template <class T> struct Complex {
        T r, i;
        Complex(T _r = 0, T _i = 0) : r(_r), i(_i) {}
        Complex<T> operator+(const Complex<T> &b) { return Complex(r + b.r, i + b.i); } // 用 member funcion 來完成（因為不想放進 namespace 裡）
        Complex<T> operator-(const Complex<T> &b) { return Complex(r - b.r, i - b.i); }
        // 嘗試使用 --ffast-math
        Complex<T> operator*(const Complex<T> &b) __attribute__((optimize("fast-math")));
    };
    template <class T>
        Complex<T> Complex<T>::operator*(const Complex<T> &b) {
            return Complex<T>(r * b.r - i * b.i, r * b.i + i * b.r);
        }
    class FFT { // static class fft
        private:
            template <class T>
                static void change(Complex<T> y[], int len) {
                    int i, j, k;
                    for (i = 1, j = (len>>1); i < len - 1; ++i) {
                        if (i < j) swap(y[i], y[j]);
                        k = (len>>1);
                        while (j >= k) {
                            j -= k;
                            k >>= 1;
                        }
                        if (j < k) j += k;
                    }
                }
            // 嘗試使用 --ffast-math
            template <class T> static void fft(Complex<T> y[], int len, int inv) __attribute__((optimize("fast-math")));
        public:
            // 介面，輸入向量 y, y 會變成 FFT(y) / IFFT(y)
            // 參數： 向量y, 長度(2^k), IFFT?
            template <class T> static void run(Complex<T> y[], int l, bool inv = false) {
                fft(y, l, inv ? -1 : 1);
            }
    };
    template <class T>
        void FFT::fft(Complex<T> y[], int len, int inv) { // if inv:1 FFT; int:-1 IFFT
            change(y, len);
            for (int h = 2; h <= len; h <<= 1) {
                Complex<T> wn(std::cos(-inv * 2 * M_PIl / h), std::sin(-inv * 2 * M_PIl / h));
                for (int j = 0; j < len; j += h) {
                    Complex<T> w(1, 0);
                    for (int k = j; k < j + h / 2; k++) {
                        Complex<T> u = y[k];
                        Complex<T> t = w * y[k + h / 2];
                        y[k] = u + t;
                        y[k + h / 2] = u - t;
                        w = w * wn;
                    }
                }
            }
            if (inv == -1)
                for (int i = 0; i < len; i++)
                    y[i].r /= len;
        }

}; // namespace FFT_TOOL

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>

char sa[(1<<17)+10], sb[(1<<17)+10];
FFT_TOOL::Complex<double> a[1<<18], b[1<<18];
std::vector<int> res;

int main(void) {
    using namespace std;
    const double eps=1.5e-1;
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
        for (int i=0; i<sa_length; ++i) {
            a[i] = sa[ sa_length-1-i ]-'0';
        }
        for (int i=sa_length; i<digitN; ++i) a[i]=FFT_TOOL::Complex<double>(0,0);
        for (int i=0; i<sb_length; ++i) {
            b[i] = sb[ sb_length-1-i ]-'0';
        }
        for (int i=sb_length; i<digitN; ++i) b[i]=FFT_TOOL::Complex<double>(0,0);
        FFT_TOOL::FFT::run(a, digitN, false);
        FFT_TOOL::FFT::run(b, digitN, false);
        for (int i=0; i<digitN; ++i) a[i]=a[i]*b[i];
        FFT_TOOL::FFT::run(a, digitN, true);
        res.resize(digitN, 0);
        for (int i=0; i<digitN; ++i) {
            res[i] = a[i].r+eps;
        }
        for (int i=0; i<maxN-1; ++i) {
            res[i+1] += res[i]/10;
            res[i  ] %= 10;
        }
        bool detected=false;
        for (int i=maxN-1; i>=0; --i) {
            if (res[i]>0) detected=true;
            if (detected) printf("%u",res[i]);
        }
        if (!detected) putchar('0');
        puts("");
        res.clear();
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
