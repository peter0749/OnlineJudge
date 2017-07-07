#include <bits/stdc++.h>
using namespace std;

struct SUBMIT {
    string name;
    bool AC;
};

SUBMIT submit[10010];
unordered_map<string, int> ac;

int main(void) {
    int N;
    string name, status;
    cin >> N;
    for (int i=N-1; i>=0; --i) {
        cin >> name >> status;
        submit[i].name = name;
        submit[i].AC = (status=="AC");
    }
    for (int i=0; i<N; ++i) {
        name = submit[i].name;
        bool AC = submit[i].AC;
        if (ac.count(name) && ac[name]<0) continue; // ACed
        ++ac[name]; // Not 
        if(AC) ac[name] = -ac[name];
    }
    int oneAC = 0;
    int totalAC = 0;
    for (const auto &v : ac) {
        if(v.second<0) ++totalAC;
        if(v.second==-1) // 1-AC
            ++oneAC;
    }
    double acRate = (double)oneAC * 100.0L / (double)totalAC;
    cout << fixed << setprecision(0) << acRate << "%\n";
    return 0;
}
