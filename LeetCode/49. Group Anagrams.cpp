class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> solution;
        unordered_map<string, vector<int>> lookup;
        for (int i=0; i<strs.size(); ++i) {
            string key = strs[i];
            sort(key.begin(), key.end());
            if (lookup.count(key)==0)
                lookup[key] = vector<int>();
            lookup[key].push_back(i);
        }
        for (auto p : lookup) {
            vector<string> temp;
            for (auto i : p.second)
                temp.push_back(strs[i]);
            solution.push_back(temp);
        }
        return solution;
    }
};
