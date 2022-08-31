class MedianFinder {
public:
    priority_queue<int> s;
    priority_queue<int, vector<int> , greater<int>> g;
    
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        s.push(num);
        
        g.push(s.top());
        s.pop();
        
        balanceHeap();
    }
    
    void balanceHeap(){
        if(g.size() > s.size())
        {
            s.push(g.top());
            g.pop();
        }
    }
    
    double findMedian() {
        if(s.size() > g.size())
            return s.top();
        else
            return (s.top() + g.top())/2.0;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */