#include <bits/stdc++.h>
using namespace std;

set<string> player[2];

#define RL() fgets(buff, 4000, stdin)

int main(void) {
    int n,m;
    char buff[4096];
    RL();
    sscanf(buff, "%d%d", &n, &m);
    for (int i=0; i<n; ++i) {
        RL();
        sscanf(buff,"%s",buff);
        string s(buff);
        player[0].insert(s);
    }
    for (int i=0; i<m; ++i) {
        RL();
        sscanf(buff,"%s",buff);
        string s(buff);
        player[1].insert(s);
    }
    bool win=false; // 0:平局, 1:win, -1:lose
    for(int i=0, j=1; ; swap(i,j)) {
        if (player[i].empty()) {
            if (i==1) win=true;
            break;
        }
        set<string>::iterator ite = player[i].begin(); // 先隨便拿一個

        for (set<string>::iterator u=player[i].begin(); u!=player[i].end(); ++u) {
            if (player[j].count(*u)) {
                ite = u; // 找到跟對方一樣的，把他刪掉
                break;
            }
        }
        if (player[j].count(*ite)) player[j].erase(*ite); // 刪掉對面的
        player[i].erase(ite); // 刪掉自己的
    }
    if (win) cout << "YES" << endl;
    else cout << "NO" << endl;
    return 0;
}