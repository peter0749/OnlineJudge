class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        if (n==0) return result;
        
        stack<tuple<string, int, int>> stk;
        stk.push({"(", 1, 0});
        while (!stk.empty()) {
            auto top = stk.top();
            string s;
            int left, right;
            stk.pop();
            tie(s, left, right) = top;
            if (left==n && right==n)
                result.push_back(s);
            if (right<left)
                stk.push({s+")", left, right+1});
            if (left<n)
                stk.push({s+"(", left+1, right});
        }
        
        return result;
    }
};
