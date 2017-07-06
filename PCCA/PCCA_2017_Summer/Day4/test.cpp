#pragma GCC optimize ("O3")
#pragma GCC target ("avx")
#define _DEBUG
//#include <bits/stdc++.h>
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <climits>
#include <algorithm>
#include <functional>
#include <vector>
#include <map>
#include <set>
#define MAXN 800100
using namespace std;


struct {
    enum {SIZE=5000000};
    int table[SIZE];
    int prevkey[SIZE];
    map<int, int> backup;
    void init () {
        memset(table, 0x00, sizeof(table));
    }
    unsigned int hash(unsigned int x) {
        x = ((x >> 16) ^ x) * 0x45d9f3b;
        x = ((x >> 16) ^ x) * 0x45d9f3b;
        x = (x >> 16) ^ x;
        return x%SIZE;
    }
    void insert(int key, int v) {
        unsigned int idx = hash(key);
        if (table[idx]==-1) { // already conflict
            backup[key]=v;
            return;
        }
        if (!table[idx]) { // conflict
            backup[key] = v;
            backup[prevkey[idx]] = table[idx];
            table[idx] = -1; // set conflict
            return;
        }
        prevkey[idx] = key;
        table[idx] = v;
    }
    int query(int key) {
        int q = hash(key);
        if (!table[q]) return -1; // no element
        if (table[q]==-1) {
            int res = -1;
            try {
                res = backup[key];
            } catch (...) { 
                res = -1;
            }
            return res;
        }
    }
} H;

const size_t TREEND=3;
const size_t TREENN=MAXN*TREEND;
long long int  seg[TREENN]; // neg, pos
long long int lazy[TREENN];  // neg, pos
vector<  pair< pair<int,int> , long long int > > qs; // left, right, height
set< int > test;
vector<int> data;

#define LEFT(i) ((i)<<1)
#define RIGHT(i) ((i)<<1|1)

inline long long int lmax(const long long int &a, const long long int &b) {
    return a>b?a:b;
}

template <class T>
inline T operationOnPull(const T &a, const T &b) {
    return lmax(a , b);
}

template <class T>
inline T operationOnPush(const T &a, const T &b) {
    return operationOnPull<T>(a , b);
}

inline void init(int n, long long int *seg, long long int *lazy) {
    n*=TREEND;
    memset(seg, 0x00, sizeof(seg[0])*(n+1));
    memset(lazy, 0x00, sizeof(lazy[0])*(n+1));
}

#define IN_RANGE (qL<=L && qR>=R)
#define OO_RANGE (L>=qR || R<=qL)

inline void _push(int lev, long long int seg[], long long int lazy[]) {
    if (!lazy[lev]) return;
    seg[LEFT(lev)] = operationOnPush<long long int>(seg[LEFT(lev)],  (lazy[LEFT(lev)] = lazy[lev])); 
    seg[RIGHT(lev)] = operationOnPush<long long int>(seg[RIGHT(lev)], (lazy[RIGHT(lev)] = lazy[lev])); 
    lazy[lev] = 0L;
}

// 更新
inline void _pull(int lev, long long int seg[]) { 
    seg[lev] = operationOnPull<long long int>(seg[LEFT(lev)] , seg[RIGHT(lev)]);
}

void update(int L, int R, int qL, int qR, int lev, int op, long long int seg[], long long int lazy[]) { 
    if (OO_RANGE) return;
    int M = (L+R)>>1;
    if (IN_RANGE) {
        seg[lev] = operationOnPull<long long int>(seg[lev],op);
        lazy[lev] = op;
        return;
    }
    _push(lev, seg, lazy);
    update(L, M, qL, qR, LEFT(lev), op, seg, lazy);
    update(M, R, qL,qR, RIGHT(lev),op,seg, lazy);
    _pull(lev, seg);
}

int query(int L, int R, int qL, int qR, int flag, long long int seg[], long long int lazy[]) {
    int M=(L+R)>>1;
    if (OO_RANGE) return 0; // 沒東西
    if (IN_RANGE) return seg[flag];
    _push(flag, seg, lazy);
    long long int left=0, right=0;
    left = query(L,M,qL,qR,LEFT(flag),seg,lazy);
    right = query(M,R,qL,qR,RIGHT(flag),seg,lazy);
    return operationOnPull<long long int>(left, right);
}

int main(void){
    int N;
    scanf("%d", &N);
    qs.reserve(N);
    for (int i=0; i<N; ++i) {
        int a, b;
        long long int c;
        scanf("%d%d%lld", &a, &b, &c);
        test.insert(a); test.insert(b);
        qs.push_back( make_pair(make_pair(a,b), c) );
    }
    sort(qs.begin(), qs.end());
    data.reserve(test.size()+1);
    data.push_back(0);
    int seg_n = 0;
    for (set<int>::iterator v=test.begin(); v!=test.end(); ++v) {
        data.push_back(*v);
        H.insert(*v, ++seg_n);
    }
    test.clear();

    //for (map<int, int>::iterator v=s.begin(); v!=s.end(); ++v) cout << v->first << ':' << v->second << endl;
    init(seg_n+1, seg, lazy);
    for (vector< pair< pair<int,int>, long long int> >::iterator v=qs.begin(); v!=qs.end(); ++v) {
        update(1, seg_n, H.query(v->first.first), H.query(v->first.second), 1, v->second, seg, lazy);
    }
    long long int sum = 0;
    for (int i=1; i<seg_n; ++i) {
        long long int res = query(1, seg_n, i, i+1, 1, seg, lazy);
        long long int temp = data[i+1]-data[i];
        //cout << res << '*' << temp << endl;
        sum += res*temp;
    }
    printf("%lld\n", sum);
    return 0;
}
