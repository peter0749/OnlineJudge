#include <bits/stdc++.h>
using namespace std;

const size_t MAXN=20;
long double facs[MAXN];

void mk_fac(void) {
    facs[0]=1;
    for (int i=1; i<MAXN; ++i) facs[i] = facs[i-1]*((long double)i);
}

inline long double comp(const int &n, const int &k) { return facs[n]/(facs[n-k]*facs[k]); }

int main(void) {
    string str1, str2;
    mk_fac();
    cin >> str1;
    cin >> str2;
    int pos1=0, neg1=0, pos2=0, neg2=0, unk=0, diff=0;
    for (int i=0; i<str1.length(); ++i) {
        if (str1[i]=='+') ++pos1;
        else ++neg1;
        if (str2[i]=='+') ++pos2;
        else if (str2[i]=='-') ++neg2;
        else ++unk;
    }
    diff = abs((pos1-neg1)-(pos2-neg2));
    if(diff%2!=unk%2||unk<diff) cout << "0" << endl;
    else {
        if (diff%2) { // odd
            cout << fixed << setprecision(11) << (comp(unk, unk/2+1+(diff-1)/2)*pow(0.5,unk)) << endl;
        } else { // even
            if (diff==0) {
                cout << fixed << setprecision(11) << (comp(unk, unk/2)*pow(0.5,unk)) << endl;
            } else {
                cout << fixed << setprecision(11) << (comp(unk, unk/2+diff/2)*pow(0.5,unk)) << endl;
            }
        }
    }
    return 0;
}
