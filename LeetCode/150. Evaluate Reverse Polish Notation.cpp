class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        if (tokens.size()==1)
            return stoi(tokens[0]);
        stack<long long> stk;
        for (int i=0; i<2; ++i)
            stk.push(stoi(tokens[i]));
        for (int i=2; i<tokens.size(); ++i) {
            if (tokens[i]=="+" || tokens[i]=="-" || tokens[i]=="*" || tokens[i]=="/") {
                long long op2 = stk.top(); stk.pop();
                long long op1 = stk.top(); stk.pop();
                if (tokens[i]=="+")
                    stk.push(op1+op2);
                if (tokens[i]=="-")
                    stk.push(op1-op2);
                if (tokens[i]=="*")
                    stk.push(op1*op2);
                if (tokens[i]=="/")
                    stk.push(op1/op2);
            } else {
                stk.push(stoi(tokens[i]));
            }
        }
        return stk.top();
    }
};
