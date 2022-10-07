class MyCalendar {
public:
    map<int,int> mp;
    
    MyCalendar() {
        
    }
    
    bool book(int start, int end) {
        auto next = mp.upper_bound(start);
        if(next != mp.end() &&   (*next).second < end)
            return false;
        
        mp.insert({end,start});
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */