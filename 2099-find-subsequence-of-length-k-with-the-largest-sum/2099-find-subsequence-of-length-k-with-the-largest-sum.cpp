class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {

        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        
        for(int i=0;i<nums.size();i++)
        {
            pq.push({nums[i], i});
            if(pq.size() > k)
                pq.pop();
        }
        
        vector<pair<int,int>> ans;
        while(!pq.empty())
        {
            auto x = pq.top();
            pq.pop();
            ans.push_back({x.second, x.first});
        }
        
        sort(ans.begin(), ans.end());
        
        vector<int> res;
        for(auto x:ans)
        {
            res.push_back(x.second);
        }
        return res;
    }
};