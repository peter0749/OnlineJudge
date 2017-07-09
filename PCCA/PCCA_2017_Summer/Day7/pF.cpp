#pragma GCC optimize ("O3")
#pragma GCC target ("avx2")
#include <bits/stdc++.h>
#define PB push_back
#define MAXN 10310
#define BOARD 10020
#define FAREST 10000
#define NSIZE 110
using namespace std;

typedef struct
{
    int to, cap, rev;
} NODE;
typedef pair<int, int> PII;
typedef vector< NODE > Net;
typedef vector< PII > G;
const int S=MAXN-2, T=MAXN-1;

int N;
Net graph[MAXN], base[MAXN];//0~10000, 10001~10100
G   data;
vector<int> seg;
int level[MAXN];
int iter[MAXN];

void bfs(int s) {
    memset(level, -1, sizeof(level));
    queue<int> que;
    level[s] = 0;
    que.push(s);
    while(!que.empty()) {
        int v = que.front(); que.pop();
        for(int i=0; i<graph[v].size(); ++i) {
            NODE &e = graph[v][i];
            if(e.cap >0 && level[e.to]<0) {
                level[e.to] = level[v]+1;
                que.push(e.to);
            }
        }
    }
}

int dfs(int v, int t, int f) {
    if(v==t) return f;
    for(int &i = iter[v]; i<graph[v].size(); ++i) {
        NODE &e = graph[v][i];
        if(e.cap >0 && level[v]< level[e.to]) {
            int d = dfs(e.to, t, min(f, e.cap));
            if( d> 0) {
                e.cap -= d;
                graph[e.to][e.rev].cap +=d ;
                return d;
            }
        }
    }
    return 0;
}

int max_flow()
{
    int flow=0;
    while(1) {
        bfs(S);
        if (level[T]<0) return flow;
        memset(iter, 0x00, sizeof(iter));
        int f;
        while((f=dfs(S,T,1e9+1))>0) {
            flow += f;
        }
    }
    return 0;
}

void add_edge(Net *net, int from, int to, int cap) {
    net[from].PB((NODE){to,cap,(int)net[to].size()});
    net[to].PB((NODE){from, 0, (int)net[from].size()-1});
}

void build() { // build a huge net
    // S=MAXN-2, T=MAXN-1
    for (int i=1; i<seg.size(); ++i) {
        //add_edge(base, S, i-1, 1e6); // S -> segments(inf quantities)
        add_edge(base, S, i-1, seg[i]-seg[i-1]); // S -> segments(inf quantities)
    }
    // so that quantized segment node is: [0, seg.size()-1)
}

void rebuild(int target) {
    // S=MAXN-2, T=MAXN-1
#define NEWNODE1(i) (seg.size()+(i))
#define NEWNODE2(i) (seg.size()+data.size()+(i))
    for (int i=0; i<MAXN; ++i) {
        graph[i].clear();
        graph[i] = base[i]; // copy assignment
    }
    for (int i=0; i<data.size(); ++i) {
        const int &l = data[i].first;
        const int &r = data[i].second;
        int left = lower_bound(seg.begin(), seg.end(), l)-seg.begin();
        int right= lower_bound(seg.begin(), seg.end(), r)-seg.begin();
        //cout << left << ' ' << right << endl;
        for (int j=left; j<right; ++j) {
            add_edge(graph, j, NEWNODE1(i), seg[j+1]-seg[j]); // segments -> dishes
        }
        add_edge(graph, NEWNODE1(i), NEWNODE2(i), target);
        add_edge(graph, NEWNODE2(i), T, target); // dishes -> groumet
    }
}

inline bool checker(int d) {
    rebuild(d);
    int res = max_flow();
    //cout << "target: " << d*N << ':' << res << endl;
    return d*N==res;
}

int main(void) {
    set<int> s;
    scanf("%d", &N);
    for (int i=0; i<N; ++i) {
        int l ,r; scanf("%d%d", &l, &r);
        if (l>r) swap(l,r);
        data.push_back(make_pair(l,r));
        s.insert(l); s.insert(r);
    }

    s.insert(0); // always first element
    s.insert(FAREST);
    seg.reserve(s.size());
    for (set<int>::iterator v=s.begin(); v!=s.end(); ++v) seg.push_back(*v);
    s.clear();
    //for (const auto &v : seg) cout << v << endl;

    build();
    /*
    int maxv = 0;
    for (int i=0; i<1e3; ++i) {
        checker(i);
    }
    */
    int l=0, r=1.5e4;
    // binary search
    while(r-l>1) {
        int m = (l+r)>>1;
        if (checker(m)) l = m;
        else r = m;
    }
    printf("%d\n", l*N);
    return 0;
}
