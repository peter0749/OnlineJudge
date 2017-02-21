#include <bits/stdc++.h>
using namespace std;

#define PB push_back
#define F first
#define S second
typedef long long int UT;
typedef pair< UT, UT > PII;
const PII p(29,31), q(10000103, 10000121);
const int MAXN(1010);
PII h[MAXN], rh[MAXN], cache[MAXN];

class Solution {
    public:
        string longestPalindrome(string &s) {
            get_pow(cache, p, s.length(), q);//lazy dog
            get_hash(s,h); get_hash(s,rh,true);
            int lb=0, hb=s.length()/2+3;//No need to warry.
            int eoff=-1, ooff=-1;
            while(hb - lb > 1) {
                int mid=(lb+hb)/2;
                int idx = check(s.length(), h, rh, cache[mid*2], mid*2);
                if( idx!=-1 ) {
                    eoff=idx;
                    lb=mid;
                } else hb=mid;
            }
            int ev=lb;

            lb=0, hb=s.length()/2+3;
            while(hb - lb > 1) {
                int mid=(lb+hb)/2;
                int idx = check(s.length(), h, rh, cache[mid*2+1], mid*2+1);
                if( idx!=-1 ) {
                    ooff=idx;
                    lb=mid;
                } else hb=mid;
            }
            int od=lb;

            if(eoff!=-1 && ooff!=-1) {
                return od*2+1>ev*2?s.substr(ooff, od*2+1):s.substr(eoff, ev*2);
            } 
            if(eoff!=-1) return s.substr(eoff, ev*2);
            if(ooff!=-1) return s.substr(ooff, od*2+1);
            return s.substr(0,1);
        }

        inline void get_hash(string &s, PII *h, bool rev=false) {
            h[0].F=h[0].S=h[s.length()+1].S=h[s.length()+1].F=0;
            ++h; // index is shifted
            if(!rev) {
                for(int i=0; i!=s.length(); ++i ){
                    h[i].F = ((h[i-1].F*p.F%q.F)+s[i]+1)%q.F;
                    h[i].S = ((h[i-1].S*p.S%q.S)+s[i]+1)%q.S;
                }
            } else { //reverse
                for(int i=s.length()-1, j=0; i!=-1; --i,  ++j ){
                    h[j].F = ((h[j-1].F*p.F%q.F)+s[i]+1)%q.F;
                    h[j].S = ((h[j-1].S*p.S%q.S)+s[i]+1)%q.S;
                }
            }
        }

        inline void get_pow(PII *h, const PII base, const int n, const PII P) {
            h[0].F=h[0].S=1;
            for(int i=1; i<=n; ++i) {
                h[i].F = (h[i-1].F*base.F)%P.F;
                h[i].S = (h[i-1].S*base.S)%P.S;
            }
        }

        inline int check(const int L, PII *h, PII *rh, PII const &pw, int n) {
            if(n>L) return -1;
            h++; rh++; //shift index
            UT temp1, temp2, temp3, temp4;//Lazy dog...
            for(int i=0; i+n-1<L; ++i) {
                temp1 = ((q.F - h[i-1].F*pw.F%q.F) + h[i+n-1].F)%q.F;
                temp2 = ((q.F - rh[L-i-n-1].F*pw.F%q.F) + rh[L-i-1].F)%q.F;
                temp3 = ((q.S - h[i-1].S*pw.S%q.S) + h[i+n-1].S)%q.S;
                temp4 = ((q.S - rh[L-i-n-1].S*pw.S%q.S) + rh[L-i-1].S)%q.S;
                /*
                for(int v=i; v<i+n; ++v) cout<<s[v];
                cout << endl;
                cout << temp1 << ' ';
                cout << temp2 << endl;
                cout << temp3 << ' ';
                cout << temp4 << endl;
                */
                if(temp1==temp2&&temp3==temp4) {
                    return i;
                }
            }
            return -1;
        }

};

int main(void) {
    Solution solver;
    string s;
    cin>>s;
    cout<<solver.longestPalindrome(s)<<endl;
    return 0;
}
