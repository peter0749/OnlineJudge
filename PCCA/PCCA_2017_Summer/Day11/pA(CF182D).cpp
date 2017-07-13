#pragma optimize ("O3")
#pragma target ("avx")
#include <bits/stdc++.h>

#define UT long long int
#define PII std::pair< UT, UT >
struct RollingHash {
#define MAXN 100010
#define PB push_back
#define F first
#define S second
    static const PII p, q;
    PII h[MAXN], cache[MAXN];

    inline void get_pow(const int n) {
        const PII &base = p;
        const PII &P    = q;
        PII *h = this->cache;
        h[0].F=h[0].S=1;
        for(int i=1; i<=n; ++i) {
            h[i].F = (h[i-1].F*base.F)%P.F;
            h[i].S = (h[i-1].S*base.S)%P.S;
        }
    }

    inline void get_hash(std::string &s) {
        // rev 代表是否要反向建 Hash
        PII *h = this->h;
        h[0].F=h[0].S=h[s.length()+1].S=h[s.length()+1].F=0;
        ++h; // index is shifted
        for(int i=0; i!=s.length(); ++i ){
            h[i].F = ((h[i-1].F*p.F%q.F)+(UT)(s[i]-'a')+1LL)%q.F;
            h[i].S = ((h[i-1].S*p.S%q.S)+(UT)(s[i]-'a')+1LL)%q.S;
        }

    }

    // pw 代表 在 get_pow() 得到的 hash 值
    // 下面的函數用來取得 從原字串 i 位置開始長度 n 子字串的 hash 值
    std::pair<UT,UT> partial_hash(int i, int n) {
        const PII &pw = cache[n];
        PII *h = this->h;
        ++h; //shift index
        UT temp1, temp2;//Lazy dog...
        temp1 = ((q.F - h[i-1].F*pw.F%q.F) + h[i+n-1].F)%q.F;
        temp2 = ((q.S - h[i-1].S*pw.S%q.S) + h[i+n-1].S)%q.S;
        return std::make_pair(temp1, temp2);
    }

    std::pair<UT,UT> double_self(int n, std::pair<UT,UT> target) {
        // string: *A -> *2A
        // hash  : (hA+1)*p^n, where n is length of A
        //std::pair<UT,UT> target = this->partial_hash(i, n);
        target.F = (target.F + target.F*this->cache[n].F%q.F)%q.F;
        target.S = (target.S + target.S*this->cache[n].S%q.S)%q.S;
        return target;
    }
    std::pair<UT,UT> extend_self(int i, int n, int t) {
        std::pair<UT,UT> base = this->partial_hash(i,n);
        std::pair<UT,UT> res(0,0); // 一次
        int crr_times = 0;
        int base_times = 1;
        while(t) {
            if (t&1) {
                res.F = res.F*cache[base_times*n].F%q.F;
                res.S = res.S*cache[base_times*n].S%q.S;
                res.F = (res.F+base.F)%q.F;
                res.S = (res.S+base.S)%q.S;
                crr_times += base_times;
            }
            base = this->double_self(n*base_times, base); // A -> AA -> AAAA
            t>>=1; base_times<<=1; // base length
        }
        return res;
    }
//#undef PB
//#undef F
//#undef S
#undef MAXN
};
const std::pair<UT,UT> RollingHash::p(311, 337);
const std::pair<UT,UT> RollingHash::q(10000103, 10000121);
//#undef UT
//#undef PII

using namespace std;

RollingHash ah, bh;
string a, b;

int main(void) {
    cin >> a;
    cin >> b;
    ah.get_pow((int)a.length());
    bh.get_pow((int)b.length());
    ah.get_hash(a);
    bh.get_hash(b);
    vector<int> cd;
    int la = a.length(), lb = b.length();
    int lmin = min(la, lb);
    for (int i=1; i<=lmin; ++i) {
        if (la % i == 0 && lb % i == 0) // 公因數
            cd.push_back(i);
    }
    int counter = 0;
    pair<UT,UT> ta = ah.partial_hash(0, a.length());
    pair<UT,UT> tb = bh.partial_hash(0, b.length());
    //cout << gcdab << endl;
    for (vector<int>::iterator v=cd.begin(); v!=cd.end(); ++v) {
        const int &i = *v;
        pair<UT,UT> ppa = ah.extend_self(0, i, a.length()/i);
        pair<UT,UT> ppb = bh.extend_self(0, i, b.length()/i);
        pair<UT,UT> tta = ah.partial_hash(0, i);
        pair<UT,UT> ttb = bh.partial_hash(0, i);
        /*
        cout << "A1: " << ta.F << ' ' << ppa.F << endl;
        cout << "A2: " << ta.S << ' ' << ppa.S << endl;
        cout << "B1: " << tb.F << ' ' << ppb.F << endl;
        cout << "B2: " << tb.S << ' ' << ppb.S << endl;
        cout << "AB1: " << tta.S << ' ' << ttb.S << endl;
        cout << "AB2: " << tta.F << ' ' << ttb.F << endl;
        */
        if (ta==ppa && tb==ppb && tta==ttb) ++counter;
    }
    cout << counter << endl;
    
    return 0;
}