#include <iostream>
#include <string>
#include <algorithm>
#include <functional>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <queue>

using namespace std;

int N, M;
priority_queue< pair<int,int> > que; // wei, id
vector< pair<int,int> > graph[300]; // wei, to
int dist[300];

inline int dij(void) { // from i to j
    fill(&dist[0], &dist[0]+300, 1e9+7);
    dist[1] = 0;
    while(!que.empty()) que.pop();
    que.push(make_pair(0,1));
    while(!que.empty()) {
        while( !que.empty() && que.top().first > dist[que.top().second]) que.pop();
        if (que.empty()) break;
        pair<int,int> ist = que.top(); que.pop();
        int u = ist.second;
        int w = ist.first;
        for (int i=0; i<graph[u].size(); ++i) {
            if (graph[u][i].first + w < dist[graph[u][i].second]) {
                dist[graph[u][i].second] = graph[u][i].first + w;
                que.push(make_pair(dist[graph[u][i].second], graph[u][i].second));
            }
        }
    }
    return dist[N];
}

int main(void) {
    while(cin >> N >> M && !(N==0&&M==0)) {
        for (int i=0; i<300; ++i) graph[i].clear();
        for (int i=0; i<M; ++i) {
            int u , v, w;
            cin >> u >> v >> w;
            graph[u].push_back(make_pair(w,v));
            graph[v].push_back(make_pair(w,u));
        }
        cout << dij() << endl;
    }
    return 0;
}