class MyStack {
public:
    queue<int> q1;
    queue<int> q2;
    MyStack() {
        q1 = queue<int>();  
        q2 = queue<int>();  
    }
    
    void push(int x) {
        
        q1.push(x);
        
    }
    
    int pop() {
        
        while(q1.size()!=1){
            q2.push(q1.front());
            q1.pop();
        }
        
        int x = q1.front();
        q1.pop();
        
        while(!q2.empty()){
            q1.push(q2.front());
            q2.pop();
        }
        
        return x;
        
    }
    
    int top() {
        while(q1.size()!=1){
            q2.push(q1.front());
            q1.pop();
        }
        
        int y = q1.front();
        
        q2.push(y);
        q1.pop();
        
        while(!q2.empty()){
            q1.push(q2.front());
            q2.pop();
        }
        
        return y;
        
    }
    
    bool empty() {
        
        if(q1.empty() && q2.empty()){
            return true;
        }else{
            return false;
        }
        
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */