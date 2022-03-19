class MinStack {
    stack<pair<int,int>> s;
    
public:
    MinStack() {
        
    }
    
    void push(int val) {
        if (s.empty()) {
            s.push(pair<int,int>(val, val));
        } else {
            pair<int,int> p = s.top();
            int min = p.second > val ? val : p.second;
            s.push(pair<int,int>(val,min));
        }
    }
    
    void pop() {
       s.pop();
    }
    
    int top() {
        return s.top().first;
    }
    
    int getMin() {
        return s.top().second;
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