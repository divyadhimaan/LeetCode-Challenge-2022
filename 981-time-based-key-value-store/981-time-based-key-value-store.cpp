class TimeMap {
public:
    
    unordered_map<string, unordered_map<int, string>> mp;
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        mp[key][timestamp] = value;
    }
    
    string get(string key, int timestamp) {
        
        
        if(mp.find(key) == mp.end())
        {
            return "";
        }
        string ans="";
        
        for(int currTime = timestamp; currTime >=1; currTime--)
        {
            if(mp[key].find(currTime) != mp[key].end())
                return mp[key][currTime];
        }
        
        return ans;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */