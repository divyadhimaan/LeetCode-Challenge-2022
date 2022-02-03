class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int,int> mp;
        for(int i=0;i<nums.size();i++)
        {
            mp[nums[i]] += 1;
        }
        
        int max_occurence = 0 , ans = 0;
        for(auto it =mp.begin();it!=mp.end(); ++it ) 
        { 
            if (it ->second > max_occurence) {
                ans = it->first;
                max_occurence = it->second;
            }
        }
        return ans;
    }
};