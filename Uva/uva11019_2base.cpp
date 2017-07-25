#pragma GCC optimize ("O3")
#include <cstring>
#include <functional>
#define UT long long int
struct PI {
    const static UT q;
    UT x, y;
    PI(UT x, UT y) : x(x), y(y) {}
    PI(const PI &ref) : x(ref.x), y(ref.y) {}
    PI() : x(0), y(0) {}
};
const UT PI::q(10000121); // 在 mod p 底下執行
const PI operator+(const PI &l, const PI &r) {
    PI res((l.x+r.x)%PI::q,(l.y+r.y)%PI::q);
    return res;
}
const PI operator-(const PI &l, const PI &r) {
    PI res((l.x+PI::q-r.x)%PI::q, (l.y+PI::q-r.y)%PI::q);
    return res;
}
const PI operator*(const PI &l, const PI &r) {
    PI res(l.x*r.x%PI::q, l.y*r.y%PI::q);
    return res;
}
const bool operator==(const PI &l, const PI &r) { // for std::unordered_set, std::unordered_map
    return l.x==r.x&&l.y==r.y;
}
const bool operator<(const PI &l, const PI &r) {  
    if (l.x!=r.x) return l.x<r.x;
    return l.y<r.y;
}
namespace std { // this give your custom class hash value
    template <>
    struct hash<PI> {
        // @overload
        std::size_t operator()(const PI& p) const {
            using std::hash;
            using std::pair;
            return hash<UT>()(p.x) ^ hash<UT>()(p.y);
        }
    };
};
struct RollingHash2D {
#define PB push_back
#define F first
#define S second
    enum { MAXN=1111, MAXM=1111 };
    static const PI px, py; // X向 hash 的 base, Y向 hash 的 base, mod Prime
    PI h[MAXN][MAXM];
    PI cacheX[MAXM], cacheY[MAXN]; // power of base X, power of base Y

    inline void get_pow(const int n, const int m) { // Hash basis 冪次
        // n, 高 / m, 寬
        cacheX[0].x=cacheX[0].y=1;
        cacheY[0].x=cacheY[0].y=1;
        for (int i=1; i<=n; ++i) {
            cacheY[i] = cacheY[i-1] * py;
        }
        for (int i=1; i<=m; ++i) {
            cacheX[i] = cacheX[i-1] * px;
        }
    }

    inline void get_hash(int *s, int n, int m) { // 取得 hash 表
        // n, 高 / m, 寬
        // 下面要做的事和 2D prefix sum 類似
        std::memset(h, 0x00, sizeof(PI)*MAXN*MAXM);
        for (int i=1; i<=n; ++i) {
            PI sum(0,0);
            for (int j=1; j<=m; ++j) {
                UT val = (UT)(s[(i-1)*m+j-1]+1);
                PI S(val, val);
                sum = sum * px + S; // X 向 hash
                h[i][j] = h[i-1][j] * py + sum;     // Y 向 hash
            }
        }
    }

    PI partial_hash(int i, int j, int n, int m) {
        // i: row; j: col; n: 高; m: 寬
        // 從 s[i][j] 往下看 nxm 大小矩陣，所對應的 hash 值
        const PI &pwX = cacheX[m]; // pX^m
        const PI &pwY = cacheY[n]; // pY^n
        PI result = h[i+n][j+m] - (h[i][j+m]*pwY + h[i+n][j]*pwX) + h[i][j]*pwX*pwY;
        // 小心 overflow
        return result;
    }
#undef PB
#undef F
#undef S
};
const PI RollingHash2D::px(47,331); // X, Y 個使用兩組 base, 就不怕碰撞了
const PI RollingHash2D::py(337,37);

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
        PI patV = pattH2D.partial_hash(0,0,th,tw);
        for (int i=0; i+th<=sh; ++i) for (int j=0; j+tw<=sw; ++j)
            if (stringH2D.partial_hash(i,j,th,tw)==patV) ++cnt;
        cout << cnt << endl;
    }
    return 0;
}
