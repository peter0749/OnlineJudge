class UnionFind {
public:
    vector<int> par;
    vector<int> rank; // "flatness"
    UnionFind(int N) : par(N, 0), rank(N, 0) {
        for (int i=0; i<N; ++i)
            par[i] = i;
    }
    int find(int num) {
        if (par[num] == num)
            return num;
        return par[num] = find(par[num]);
    }
    bool same(int num1, int num2) {
        return find(num1) == find(num2);
    }
    void Union(int num1, int num2) {
        int p1 = find(num1);
        int p2 = find(num2);
        if (rank[p1] > rank[p2])
            par[p2] = p1;
        else if (rank[p1] < rank[p2])
            par[p1] = p2;
        else {
            par[p1] = p2;
            ++rank[p2];
        }
    }
};

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.size()==0) return 0;
        if (nums.size()==1) return 1;
        
        int N = nums.size();
        
        unordered_map<int,int> discrete; // value -> index
        vector<int> counting(N, 0);
        UnionFind uf(N);
        
        for (int i=0; i<N; ++i) {
            int v = nums[i];
            if (discrete.count(v))
                continue;
            discrete[v] = i;
            for (int j=-1; j<=1; ++j) {
                int neighbor = v+j;
                if (discrete.count(neighbor))
                    uf.Union(discrete[v], discrete[neighbor]);
            }
        }
        
        for (int i=0; i<N; ++i)
            ++counting[uf.find(i)];
        
        return *max_element(counting.begin(), counting.end());
    }
};
