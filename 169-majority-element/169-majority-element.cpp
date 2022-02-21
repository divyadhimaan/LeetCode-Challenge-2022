class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int,int> mp;
        for(int i=0;i<nums.size();i++)
        {
            mp[nums[i]] += 1;
        }
        
        int max_occurence = 0 , ans = 0;
        for(auto x: mp)
        {
            if(x.second > max_occurence)
            {
                ans = x.first;
                max_occurence = x.second;
            }
        }
        return ans;
    }
};