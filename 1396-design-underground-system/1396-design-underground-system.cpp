class UndergroundSystem {
public:
    //(start_station:end_station) -> {total_time, no_of_trips}
    unordered_map <string, pair<long long, int>> stationTime;
    //(id) -> {stationName, time}
    unordered_map <int, pair<string,int>> In;
    UndergroundSystem() {
        stationTime.clear();
        In.clear();
    }
    
    void checkIn(int id, string stationName, int t) {
        if(In.find(id) == In.end())
            In[id] = {stationName, t};
    }
    
    void checkOut(int id, string stationName, int t) {
        auto& inDetails = In[id];
        string startStation = inDetails.first;
        int startTime = inDetails.second;
        
        string key = startStation + ":" + stationName;
        int diff = t - startTime;
        
        if(stationTime.find(key)!= stationTime.end())
        {
            stationTime[key].first += diff;
            stationTime[key].second++;
        }else {
            stationTime[key] = {diff, 1};
        }
        In.erase(id);
    }
    
    double getAverageTime(string startStation, string endStation) {
        string key = startStation + ":" + endStation;
        
        auto& info = stationTime[key];
        double ans = (double)info.first / (double)info.second;
        return ans;
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */