// AC, 壓底線？ 2829MS/3000MS, 12380K
#pragma GCC target ("avx")
#pragma GCC optimize ("O3")
#include <cstring>
#include <functional>
#define UT long int
struct RollingHash2D {
#define PB push_back
#define F first
#define S second
    enum { MAXN=1002, MAXM=1002 };
    static const UT px, py; // X向 hash 的 base, Y向 hash 的 base, mod Prime
    UT h[MAXN][MAXM];
    UT cacheX[MAXM], cacheY[MAXN];

    inline void get_pow(const int n, const int m) { // Hash basis 冪次
        // n, 高 / m, 寬
        cacheX[0]=1;
        cacheY[0]=1;
        for (int i=1; i<=n; ++i) {
            cacheY[i] = cacheY[i-1]*py;
        }
        for (int i=1; i<=m; ++i) {
            cacheX[i] = cacheX[i-1]*px;
        }
    }

    inline void get_hash(int *s, int n, int m) { // 取得 hash 表
        // n, 高 / m, 寬
        // 下面要做的事和 2D prefix sum 類似
        std::memset(h, 0x00, sizeof(UT)*MAXN*MAXM);
        for (int i=1; i<=n; ++i) {
            int sum=0;
            for (int j=1; j<=m; ++j) {
                sum = sum*px + s[(i-1)*m+j-1] + 1; // X 向 hash
                h[i][j] = h[i-1][j]*py + sum;     // Y 向 hash
            }
        }
    }

    inline UT partial_hash(int i, int j, int n, int m) {
        // i: row; j: col; n: 高; m: 寬
        // 從 s[i][j] 往下看 nxm 大小矩陣，所對應的 hash 值
        const UT &pwX = cacheX[m]; // pX^m
        const UT &pwY = cacheY[n]; // pY^n
        UT result = \
        h[i+n][j+m] - (h[i][j+m]*pwY + h[i+n][j]*pwX) + h[i][j]*pwX*pwY;
        // 小心 overflow
        return result;
    }
#undef PB
#undef F
#undef S
};
const UT RollingHash2D::px(3);
const UT RollingHash2D::py(5);
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <map>

RollingHash2D str, pat;
int s[1000010], p[10010];
std::map<UT,int> UTmap;

int main(void) {
    using namespace std;
    char buffer[3072];
#define RL() (fgets(buffer,3000,stdin))
    str.get_pow(66,66);
    pat.get_pow(55,55);
    int cases=0;
    while(RL()!=NULL) {
        int N,M,T,P,Q;
        sscanf(buffer,"%d %d %d %d %d",&N,&M,&T,&P,&Q);
        if (N==0&&M==0&&T==0&&P==0&&Q==0) break;
        for (int i=0, k=0; i<N; ++i) {
            RL();
            for (int j=0; j<M; ++j, ++k) {
                s[k] = (buffer[j]=='0'?1:0);
            }
        }
        str.get_hash(s,N,M);
        for (int t=0; t<T; ++t) {
            RL();
            for (int i=0, k=0; i<P; ++i) {
                RL();
                for (int j=0; j<Q; ++j, ++k) {
                    p[k] = (buffer[j]=='0'?1:0);
                }
            }
            pat.get_hash(p,P,Q);
            ++UTmap[pat.partial_hash(0,0,P,Q)];
        }
        int cnt=0;
        // O(W^2 * lgT)
        for (int i=0; i+P<=N; ++i) {
            for (int j=0; j+Q<=M; ++j) {
                map<UT,int>::iterator it = \
                    UTmap.find(str.partial_hash(i,j,P,Q));
                if(it!=UTmap.end()) {
                    cnt += it->second;
                    UTmap.erase(it);
                }
            }
        }
        ++cases;
        printf("Case %d: %d\n", cases, cnt);
        UTmap.clear();
    }
    return 0;
}
