class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> sol;
        
        for (auto v : intervals) {
            if (sol.size() == 0)
                sol.push_back(v);
            auto last = sol.back();
            // overlap
            if (v[0]<=last[1]) {
                sol.pop_back();
                sol.push_back(vector<int>{last[0], max(last[1],v[1])});
            } else {
                sol.push_back(v);
            }
        }
        
        return sol;
    }
};
