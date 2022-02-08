class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        int mx = *max_element(nums.begin(),nums.end());
        
        for(int i = 0; i< nums.size(); i++)
        {
            if(mx < nums[i]*2 && mx != nums[i])
                return -1;
        }
        return max_element(nums.begin(),nums.end()) - nums.begin();
    }
};