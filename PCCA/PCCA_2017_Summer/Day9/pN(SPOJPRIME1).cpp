#pragma GCC optimize ("O3")
#include <iostream>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <functional>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> prime_list;
const size_t MAXN = 2000000;
bool is_prime[MAXN];

void mk_prime(void) {
    prime_list.push_back(2);
    fill(&is_prime[0], &is_prime[0]+MAXN, true);
    for (int i=3; i<MAXN; i+=2) {
        if (is_prime[i]) {
            prime_list.push_back(i);
            for (int j=i+i; j<MAXN; j+=i) {
                is_prime[j] = false;
            }
        }
    }
}

bool isprime(int n) {
    if (n==2) return true;
    if (n%2==0) return false;
    if (n<MAXN) return is_prime[n];
    for (const auto &v : prime_list) {
        if (v*v>n) return true;
        if (n%v==0) return false;
    }
    return true;
}

inline pair<int,int> startp(int a, int b) {
    return make_pair( lower_bound(prime_list.begin(), prime_list.end(), a)-prime_list.begin() ,
            lower_bound(prime_list.begin(), prime_list.end(), b)-prime_list.begin());
}

void solv(int a, int b) {
    if (a>b) swap(a,b);
    pair<int,int> st = startp(a,b);
    if (st.first>=prime_list.size()||st.first<0) {
        if (a%2==0) ++a;
        if (b%2==0) --b;
        for (int i=a; i<=b; i+=2) if (isprime(i)) printf("%d\n", i);
    } else if (st.second>=prime_list.size()||st.second<0) {
        for (int i=st.first; i<prime_list.size(); ++i) if (prime_list[i]>=a) printf("%d\n", prime_list[i]);
        for (int i=prime_list[prime_list.size()-1]+2; i<=b; i+=2) if (isprime(i)) printf("%d\n", i);
    } else {
        for (int i=st.first; i<=st.second && prime_list[i]<=b; ++i) if (prime_list[i]>=a) printf("%d\n", prime_list[i]);
    }
}


int main(void) {
    mk_prime();
    int T;
    scanf("%d", &T);
    while(T--) {
        int a, b;
        scanf("%d%d", &a, &b);
        solv(a, b);
        puts("");
    }
    return 0;
}