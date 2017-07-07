#include <bits/stdc++.h>
#define X first
#define Y second
using namespace std;

vector< pair<int,int> > points;
vector< pair<int,int> > out;

int main(void) {
    int T=0;
    int N;
    while(cin >> N) {
        ++T;
        points.clear();
        out.clear();
        for (int i=0; i<N; ++i) {
            int x, y;
            cin >> x >> y;
            points.push_back(make_pair(x,-y));
        }
        sort(points.begin(), points.end());
        for (int i=0; i<N; ) {
            int x = points[i].X;
            int y = -points[i].Y; // max y amont same x
            while (!out.empty() && out[out.size()-1].Y <= y) out.erase(out.end()-1, out.end()); 
            out.push_back(make_pair(x,y));
            for (++i; i<N && points[i].X==x; ++i);
        }
        cout << "Case " << T << ":\n";
        cout << "Dominate Point: " << out.size() << '\n';
        for (int i=0; i<out.size(); ++i)
            cout << '(' << out[i].X << ',' << out[i].Y << ")\n";
    }
    return 0;
}
