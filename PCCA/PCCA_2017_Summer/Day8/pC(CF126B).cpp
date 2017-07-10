#include <bits/stdc++.h>
using namespace std;

#define PB push_back
#define F first
#define S second
typedef long long int UT;
typedef pair< UT, UT > PII;
const PII p(311,337), q(1e9+7, 1e9+87);
const int MAXN(1000100);
PII h[MAXN], lookup[MAXN];

inline void get_pow(PII *h, const int n) {
    h[0].F=h[0].S=1;
    for(int i=1; i<=n; ++i) {
        h[i].F = (h[i-1].F*p.F)%q.F;
        h[i].S = (h[i-1].S*p.S)%q.S;
    }
}

inline void get_hash(string &s, PII *h) {
    // rev 代表是否要反向建 Hash
    h[0].F=h[0].S=h[s.length()+1].S=h[s.length()+1].F=0;
    ++h; // index is shifted
    for(int i=0; i!=s.length(); ++i ){
        h[i].F = ((h[i-1].F*p.F%q.F)+(UT)(s[i]-'a')+1)%q.F;
        h[i].S = ((h[i-1].S*p.S%q.S)+(UT)(s[i]-'a')+1)%q.S;
    }
}

// pw 代表 在 get_pow() 得到的 hash 值
// 下面的函數用來取得 從原字串 i 位置開始長度 n 子字串的 hash 值
inline PII partial_hash(PII *h, int i, int n) {
    h++; //shift index
    UT temp1, temp2;//Lazy dog...
    temp1 = ((q.F - h[i-1].F*lookup[n].F%q.F) + h[i+n-1].F)%q.F;
    temp2 = ((q.S - h[i-1].S*lookup[n].S%q.S) + h[i+n-1].S)%q.S;
    return make_pair(temp1, temp2);
}

string stone;
vector<int> potential;

inline bool check(int n) {
    return (partial_hash(h, 0, n)==partial_hash(h, stone.length()-n, n));
}

bool check2(int n) {
    for (int i=1; i+n<stone.length(); ++i) if (partial_hash(h, 0, n)==partial_hash(h, i, n)) return true;
    return false;
}

int main(void) {
    cin >> stone;
    get_pow(lookup, stone.length());
    get_hash(stone, h);
    for (int i=1; i<=stone.length(); ++i) {
        if (check(i)) potential.push_back(i);
    }
    /*
    for (const int &v : potential) {
        cout << stone.substr(0,v) << endl;
        cout << check2(v) << endl;
    }
    */
    int l=-1, r=potential.size();
    while(r-l>1) {
        int m = (l+r)>>1;
        if (check2(potential[m])) l = m;
        else r = m;
    }
    if (l==-1) cout << "Just a legend" << endl;
    else cout << stone.substr(0, potential[l]) << endl;
    return 0;
}
