class Solution {
public:
    int solve(vector<int> &nums, int i, int j, vector<int> &dp)
    {
        if(i > j)
            return 0;
        
        if(dp[j] != -1)
            return dp[j];
        
        int take = nums[j] + solve(nums,i, j-2, dp);
        int not_take = solve(nums, i, j-1, dp);
        
        return dp[j] = max(take, not_take);
        
    }
    
    int rob(vector<int>& nums) {
        if(nums.size()==1)
            return nums[0];
        
        vector<int> dp1(nums.size(),-1);
        vector<int> dp2(nums.size(),-1);
        
        return max(solve(nums, 1, nums.size()-1, dp1), solve(nums, 0, nums.size()-2, dp2));
    }
};