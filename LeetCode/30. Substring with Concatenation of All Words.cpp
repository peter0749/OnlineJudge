class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> solution;
        if (words.size()==0) return solution;
        unordered_map<string, int> target;
        for (auto st : words) {
            if (target.count(st)==0)
                target[st] = 0;
            ++target[st];
        }
        int L = words[0].length();
        int N = words.size();
        int end = s.size()-L*N;
        for (int i=0; i<end+1; ++i) {
            unordered_map<string, int> counter;
            for (int j=0; j<N; ++j) {
                string ss = s.substr(i+j*L, L);
                if (target.count(ss)==0) break;
                if (counter.count(ss)==0)
                    counter[ss] = 0;
                ++counter[ss];
            }
            bool success = true;
            for (auto p : target) {
                if (counter.count(p.first)==0 || counter[p.first]!=p.second) {
                    success = false;
                    break;
                }
            }
            if (success)
                solution.push_back(i);
        }
        return solution;
    }
};
