#include <iostream>
#include <string>
#include <map>
#include <cstdio>
#include <cstdlib>
#include <cstring>

using namespace std;

bool player[1001][501];
bool mask[1001];

int main(void) {
    //ios::sync_with_stdio(false);
    int T,m,n;
    char YN;
    int yes,no;
    int total;
    cin >> T;
    while (T--) {
        cin >> m >> n;
        memset(player,0x00,sizeof(player));
        for (int i=0; i<m; ++i) {
            for (int j=0; j<n; ++j) {
                cin>>YN;
                player[i][j] = (YN=='Y');
            }
        }
        memset(mask,0x00,sizeof(mask));
        for (int i=0; i<n; ++i) {
            yes=0; no=0, total=0;
            for (int j=0; j<m; ++j) {
                if (!mask[j]) {
                    ++total;
                    if (player[j][i]) {
                        ++yes;
                    } else  {
                        ++no;
                    }
                }
            }
            bool test = (yes>no); // yes 淘汰
            if ( yes!=no && yes!=total && no!=total) {
                for (int j=0; j<m; ++j) {
                    mask[j] |= (test&player[j][i])|!(test|player[j][i]);
                }
            }
        }
        int k=0;
        for (; k<m && mask[k]; ++k);
        cout << k+1;
        for (++k; k<m; ++k) {
            if (!mask[k]) cout << ' ' << k+1;
        }
        cout << endl;
    }
}
