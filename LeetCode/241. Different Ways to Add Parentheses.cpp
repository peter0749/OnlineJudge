class Solution {
public:
    unordered_map<string, vector<int> > memory;
    vector<int> diffWaysToCompute(string expression) {
        if (memory.count(expression))
            return memory[expression];
        vector<int> results;
        for (int i=0; i<expression.size(); ++i) {
            if (expression[i] == '+' || expression[i] == '-' || expression[i] == '*') {
                vector<int> leftVals = diffWaysToCompute(expression.substr(0, i));
                vector<int> rightVals = diffWaysToCompute(expression.substr(i+1));
                for (int left : leftVals) {
                    for (int right : rightVals) {
                        if (expression[i] == '+')
                            results.push_back(left + right);
                        else if (expression[i] == '-')
                            results.push_back(left - right);
                        else
                            results.push_back(left * right);
                    }
                }
            }
        }
        if (results.empty()) {
            results.push_back(stoi(expression));
        }
        return memory[expression] = results;
    }
};
