#include <cstring>
#include <functional>

#define UT long int
struct RollingHash2D {
#define PB push_back
#define F first
#define S second
    enum { MAXN=101, MAXM=101 };
    static const UT px, py, q; // X向 hash 的 base, Y向 hash 的 base, mod Prime
    UT h[MAXN][MAXM];
    UT cacheX[MAXM], cacheY[MAXN];

    inline int mulmod (int a, int b, int m) { // 快速模
        int d, r;
        if(a==0 or b==0) return 0;
        if(a==1 or b==1) return (a>b?a:b);
        __asm__("mull %4;"
                "divl %2"
                : "=d" (r), "=a"(d)
                : "r"(m), "a"(a), "d"(b));
        return  r;
    }

    inline void get_pow(const int n, const int m) { // Hash basis 冪次
        // n, 高 / m, 寬
        cacheX[0]=1;
        cacheY[0]=1;
        for (int i=1; i<=n; ++i) {
            cacheY[i] = this->mulmod(cacheY[i-1], py, q);
        }
        for (int i=1; i<=m; ++i) {
            cacheX[i] = this->mulmod(cacheX[i-1], px, q);
        }
    }

    inline void get_hash(int *s, int n, int m) { // 取得 hash 表
        // n, 高 / m, 寬
        // 下面要做的事和 2D prefix sum 類似
        std::memset(h, 0x00, sizeof(UT)*MAXN*MAXM);
        for (int i=1; i<=n; ++i) {
            int sum=0;
            for (int j=1; j<=m; ++j) {
                sum = (this->mulmod(sum, px, q) + (s[(i-1)*m+j-1]+1))%q; // X 向 hash
                h[i][j] = (this->mulmod(h[i-1][j],py,q) + sum)%q;     // Y 向 hash
            }
        }
    }

    UT partial_hash(int i, int j, int n, int m) {
        // i: row; j: col; n: 高; m: 寬
        // 從 s[i][j] 往下看 nxm 大小矩陣，所對應的 hash 值
        const UT &pwX = cacheX[m]; // pX^m
        const UT &pwY = cacheY[n]; // pY^n
        UT result = \
        ((h[i+n][j+m] + q - (h[i][j+m]*pwY + h[i+n][j]*pwX)%q)%q + this->mulmod(h[i][j],this->mulmod(pwX,pwY,q),q))%q;
        // 小心 overflow
        return result;
    }
#undef PB
#undef F
#undef S
};
//const UT RollingHash2D::px(311);
const UT RollingHash2D::px(31);
//const UT RollingHash2D::py(337);
const UT RollingHash2D::py(337);
const UT RollingHash2D::q(10000121); // 一些常數
#undef UT

int string2D[7][7] = {
    0, 0, 1, 1, 2, 3, 5,
    3, 1, 0, 9, 11, 13, 15,
    2, 3, 0, 8, 13, 0, 1,
    0, 0, 1, 1, 2, 3, 4,
    0, 7, 1, 5, 1, 0, 0, // (4, 4)
    3, 1, 0, 0, 3, 0, 7, //
    1, 4, 0, 0, 1, 3, 2
                ////
};

int patt[2][2] = { 
    1, 0,
    3, 0
    //5, 7,
    //3, 5 
};
RollingHash2D stringH2D;
RollingHash2D pattH2D;
#include <iostream>
#include <iomanip>
int main(void) {
    using namespace std;
    cout << "2D string to match:" << endl;
    for (int i=0; i<7; ++i) {
        for (int j=0; j<7; ++j)
            cout << setw(3) << string2D[i][j];
        if (i==4||i==1) cout << "  <----- here";
        cout << endl;
    }
    cout << "pattern (this should be located at string2D[1][1] and string2D[4][4]): " << endl;
    for (int i=0; i<2; ++i) {
        for (int j=0; j<2; ++j) {
            cout << setw(3) << patt[i][j];
        }
        cout << endl;
    }
    stringH2D.get_pow(7,7);
    pattH2D.get_pow(2,2);
    stringH2D.get_hash(&string2D[0][0], 7, 7);
    pattH2D.get_hash(&patt[0][0], 2, 2);
    long int pattH = pattH2D.partial_hash(0,0,2,2);
    cout << "pattH: " << pattH << endl;
    for (int i=0; i+2<=7; ++i) {
        for (int j=0; j+2<=7; ++j) {
            long int stringH = stringH2D.partial_hash(i,j,2,2);
            if (stringH==pattH) cout << "Found! (" << i << ',' << j << ") : " << stringH << endl;
        }
    }
    return 0;
}
