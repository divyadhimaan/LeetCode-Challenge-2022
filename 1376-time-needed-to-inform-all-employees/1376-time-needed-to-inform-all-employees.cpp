class Solution {
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        unordered_map<int, vector<int>> mp;
        for(int i=0;i<n;i++)
        {
            mp[manager[i]].push_back(i);
        }
        
        queue<pair<int,int>> q;
        // employee,time
        q.push({headID, 0});
        
        int maxTime = 0;
        while(!q.empty())
        {
            auto curr = q.front();
            q.pop();
            
            int head = curr.first;
            int timetaken = curr.second;
            
            int dur = timetaken + informTime[head];
            maxTime = max(maxTime, dur);
            
            for(int sub: mp[head])
            {
                q.push({sub, dur});
            }
        }
        return maxTime;
    }
};