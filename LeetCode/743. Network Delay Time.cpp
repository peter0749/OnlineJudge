class Solution {
public:
    vector<long> bellmanFord(vector<vector<int>>& times, int n, int k) {
        // Bellman Ford Algorithm
        vector<long> dist(n, INT_MAX);
        dist[k-1] = 0;
        for (int t=0; t<n-1; ++t) {
            for (auto e : times) {
                int u(e[0]-1), v(e[1]-1), w(e[2]);
                if (dist[u] != INT_MAX)
                    dist[v] = min(dist[v], dist[u] + w);
            }
        }
        return dist;
    }
    vector<long> dijkstra(vector<vector<int>>& times, int n, int k) {
        // Bellman Ford Algorithm
        --k; // 1-base to 0-base
        vector<long> dist(n, INT_MAX);
        vector<bool> visit(n, false);
        priority_queue<pair<int,int>, vector<pair<int,int>>> heap;
        vector<vector<pair<int,int>>> graph(n, vector<pair<int,int>>());
        // Build adj list
        for (auto e : times) {
             // 1-base to 0-base
            int u(e[0]-1), v(e[1]-1), w(e[2]);
            graph[u].push_back({v, w});
        }
        dist[k] = 0;
        heap.push({0, k});
        while (!heap.empty()) {
            auto top = heap.top(); heap.pop();
            int u = top.second;
            int d = top.first;
            visit[u] = true;
            for (auto e : graph[u]) {
                int v = e.first;
                int w = e.second;
                if (visit[v]) continue;
                if (dist[u] + w < dist[v]) {
                    dist[v] = dist[u] + w;
                    heap.push({-dist[v], v});
                }
            }
        }
        return dist;
    }
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<long> dist = dijkstra(times, n, k);
        int maxTime = *max_element(dist.begin(), dist.end());
        return maxTime==INT_MAX?-1:maxTime;
    }
};
