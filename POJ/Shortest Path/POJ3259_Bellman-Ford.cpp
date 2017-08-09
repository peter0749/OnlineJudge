#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
struct EDGE {
    int from, to, cost;
    EDGE(int from, int to, int cost):from(from),to(to),cost(cost) {}
};
vector< EDGE > edge;
int dist[510];

int N, M, W, T;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> T;
    while(T--) {
        cin >> N >> M >> W;
        fill(dist, dist+510, 1e9);
        dist[0] = 0;
        edge.reserve(N+M*2+W);
        for (int i=1; i<=N; ++i) edge.push_back( EDGE(0,i,0) );
        for (int i=0; i<M; ++i) {
            int s, t, c;
            cin >> s >> t >> c;
            edge.push_back( EDGE(s,t,c) );
            edge.push_back( EDGE(t,s,c) );
        }
        for (int i=0; i<W; ++i) {
            int s, t, c;
            cin >> s >> t >> c;
            edge.push_back( EDGE(s,t,-c) );
        }
        bool neg_ring=false;
        for (int i=0; i<=N; ++i) {
            for (int j=0; j<edge.size(); ++j) {
                int new_d = dist[edge[j].from]+edge[j].cost;
                if (new_d < dist[edge[j].to]) {
                    dist[edge[j].to] = new_d;
                    if (i==N) {
                        neg_ring=true;
                        i=j=1e9; // break
                    }
                }
            }
        }
        cout << (neg_ring?"YES":"NO") << endl;
        edge.clear();
    }
    return 0;
}