#include <bits/stdc++.h>
using namespace std;

int main(void) {
    int n;
    cin >> n;
    while(n--) {
        double num;
        double maxvl;
        double minvl;
        cin >> num;
        maxvl = minvl = num;
        for(int i=1; i<10; ++i) {
            cin >> num;
            maxvl = max(maxvl, num);
            minvl = min(minvl, num);
        }
        cout << "maximum:" << fixed << setprecision(2) << maxvl << endl;
        cout << "minimum:" << fixed << setprecision(2) << minvl << endl;
    }
    return 0;
}
