#pragma GCC optimize ("O3")
#include <cstring>
#include <functional>

#define UT long int
struct RollingHash2D {
#define PB push_back
#define F first
#define S second
    enum { MAXN=1002, MAXM=1002 };
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
const UT RollingHash2D::px(311);
const UT RollingHash2D::py(337);
const UT RollingHash2D::q(10000121); // 一些常數
#undef UT

RollingHash2D stringH2D;
RollingHash2D pattH2D;
#include <iostream>
#include <iomanip>

int str[1000001];
int pat[10001];

int main(void) {
    using namespace std;
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    stringH2D.get_pow(1001,1001);
    pattH2D.get_pow(101,101);
    int T; cin >> T;
    while(T--) {
        int sh,sw,th,tw;
        cin >> sh >> sw;
        for (int i=0, k=0; i<sh; ++i) for (int j=0; j<sw; ++j) {
            char c; cin >> c;
            str[k++] = (int)c;
        }
        cin >> th >> tw;
        for (int i=0, k=0; i<th; ++i) for (int j=0; j<tw; ++j) {
            char c; cin >> c;
            pat[k++] = (int)c;
        }
        stringH2D.get_hash(str, sh, sw);
        pattH2D.get_hash(pat, th, tw);
        int cnt=0;
        int patV = pattH2D.partial_hash(0,0,th,tw);
        for (int i=0; i+th<=sh; ++i) for (int j=0; j+tw<=sw; ++j)
            if (stringH2D.partial_hash(i,j,th,tw)==patV) ++cnt;
        cout << cnt << endl;
    }
    return 0;
}
