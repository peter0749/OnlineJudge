#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
    int T;
    vector<int> seq;
    cin >> T;
    while( T-- > 0) { // T approchs 0 OuO
        int n, S;
        cin >> n >> S;
        seq.clear();
        for (int i=0; i<n; ++i) {
            int temp; cin>>temp;
            seq.push_back(temp);
        }
        int i=0, j=0, crr=0, minLen=1e9;
        while (i<seq.size()) {
            //cout << i << ' ' <<  j << ' ' << crr << endl;
            if (j<seq.size() && crr<S) { // 有東西可以拿，而且現在 < 目標值
                crr+=seq[j++];
            } else { // crr>=S || j>=seq.size()
                crr-=(i<j)?seq[i++]:0; // 如果 subsequence 裡沒東西，不要移除
            }
            if (crr>=S) // update
                minLen = min(minLen, j-i);
        }
        cout << (minLen==1e9?0:minLen) << endl;
    }
    return 0;
}
