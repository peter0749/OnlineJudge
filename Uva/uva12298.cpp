#pragma GCC target ("avx")
#pragma GCC optimize ("O3")
#include <algorithm>
#include <iostream>
#include <math.h>
#include <stdio.h>
#include <string.h>
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

}; // namespace FFT

#include <cstring>

using namespace std;
using namespace FFT_TOOL;

const size_t MAXN = 262144;
int prime_list[50010];
Complex<long double> card[4][MAXN];

void mk_prime(void) {
    memset(prime_list, 0x00, sizeof(prime_list));
    for (int i = 2; i < 50010; ++i) {
        if (!prime_list[i]) {
            for (int j = i + i; j < 50010; j += i) {
                prime_list[j] = 1;
            }
        }
    }
}

int main(void) {
    int a, b, c, d;
    mk_prime();
    while (scanf("%d%d%d", &a, &b, &c) && a + b + c) {
        int d = 2;
        for (; (b + 1) * 4 > d; d <<= 1);
        for (int i = 0; i < 4; ++i) {
            for (int j = 0; j < d; ++j) {
                card[i][j] = Complex<long double>(j <= b ? prime_list[j] : 0, 0);
            }
        }
        for (int i = 0; i < c; ++i) {
            int v; char c;
            scanf("%d%c", &v, &c);
            if (c == 'S') card[0][v] = 0;
            if (c == 'H') card[1][v] = 0;
            if (c == 'C') card[2][v] = 0;
            if (c == 'D') card[3][v] = 0;
        }
        for (int i = 0; i < 4; ++i) FFT::run(card[i], d, false);
        for (int j = 0; j < d; ++j) card[0][j] = card[0][j] * card[1][j] * card[2][j] * card[3][j];
        FFT::run(card[0], d, true);
        for (int i = a; i <= b; ++i)
            printf("%lld\n", (long long)(card[0][i].r + 0.5L));
        puts("");
    }
    return 0;
}
