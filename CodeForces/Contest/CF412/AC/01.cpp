#include <bits/stdc++.h>
using namespace std;

int main(void) {
    bool rated=false;
    int n;
    vector< pair<int,int> > in;
    cin >> n;
    while (n--) {
        int a, b;
        cin >> a >> b;
        if (a!=b) {
            rated=true;
        }
        in.push_back(make_pair(a,b));
    }
    if (rated) cout << "rated\n";
    else {
        for (int i=1; i<in.size(); ++i) {
            if (in.at(i-1).second < in.at(i).second) rated=true;
        }
        if (rated) cout << "unrated\n";
        else cout << "maybe\n";
    }

    return 0;
}
