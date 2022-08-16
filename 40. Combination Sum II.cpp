class Solution {
public:
    void dfs(vector<int>& candidates, int target, int level, int sel, vector<int> &temp, vector<vector<int>> &solution, unordered_map<int,int> &count) {
        if (sel) {
            temp.push_back(candidates[level]);
            --count[candidates[level]];
        }
        if (target <= 0) {
            if (target == 0)
                solution.push_back(temp);
        } else {
            if (count[candidates[level]]>0)
                dfs(candidates, target-candidates[level], level, 1, temp, solution, count);
            if (level+1 < candidates.size()) {
                dfs(candidates, target, level+1, 0, temp, solution, count);
            }
        }
        if (sel) {
            temp.pop_back();
            ++count[candidates[level]];
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        unordered_map<int,int> count;
        for (auto v : candidates) {
            if (count.count(v) == 0)
                count[v] = 0;
            ++count[v];
        }
        vector<int> unique_candidates;
        for (auto v : count) {
            unique_candidates.push_back(v.first);
        }
        sort(unique_candidates.begin(), unique_candidates.end());
        vector<int> temp;
        vector<vector<int>> solution;
        dfs(unique_candidates, target, 0, 0, temp, solution, count);
        return solution;
    }
};
