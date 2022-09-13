class MinStack {
private:
    stack<tuple<int,int>> data;
public:
    MinStack() {
    }
    
    void push(int val) {
        if (data.size()==0) {
            data.push(tuple<int,int>(val,val));
            return;
        }
        data.push(tuple<int,int>(val, min(val, get<1>(data.top()))));
    }
    
    void pop() {
        data.pop();
    }
    
    int top() {
        return get<0>(data.top());
    }
    
    int getMin() {
        return get<1>(data.top());
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
