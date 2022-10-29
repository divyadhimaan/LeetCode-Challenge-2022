class Solution {
public:
    int earliestFullBloom(vector<int>& plantTime, vector<int>& growTime) {
        vector<pair<int,int>> v;
        for(int i=0;i<plantTime.size();i++)
        {
            v.push_back({growTime[i], plantTime[i]});
        }
        sort(v.begin(), v.end(), greater<pair<int,int>>());
        
        
        int prev_plant_time = 0;
        int max_bloom_time = -1;
        
        for(int i=0;i<v.size();i++) {
            int grow_time = v[i].first; 
            int plant_time = v[i].second;
        
            prev_plant_time += plant_time;
            
            int bloom_time = prev_plant_time + grow_time + 1; 
            
            max_bloom_time = max(max_bloom_time, bloom_time);
        }
        
        return max_bloom_time - 1; 
    }
};