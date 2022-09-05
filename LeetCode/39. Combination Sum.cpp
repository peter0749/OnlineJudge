class Solution {
public:
    // TODO: Use stack to replace recursion
    void BT(const vector<int>& candidates, int target, int pos, vector<int> &path, vector<vector<int>> &solution) {
        if (target == 0) {
            solution.push_back(path);
            return;
        }
        
        for (int i=pos; i<candidates.size(); ++i) {
            int new_target = target - candidates[i];
            if (new_target < 0) break;
            path.push_back(candidates[i]);
            BT(candidates, new_target, i, path, solution);
            path.pop_back();
        }
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> solution;
        vector<int> path;
        sort(candidates.begin(), candidates.end());
        BT(candidates, target, 0, path, solution);
        return solution;
    }
};
