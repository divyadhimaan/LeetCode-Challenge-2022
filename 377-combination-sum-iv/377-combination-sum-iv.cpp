class Solution {
public:
    
    int solve(vector<int>& nums, int target, vector<int> &dp)
    {
        if(target == 0)
            return dp[target] = 1;
        
        if(dp[target]!= -1)
            return dp[target];
        
        int count = 0;
        for(auto i:nums)
        {
            if(i<=target)
                count += solve(nums, target - i, dp);
            else 
                break;
        }
        return dp[target] = count;
    }
    
    int combinationSum4(vector<int>& nums, int target) {
        vector<int> dp(target+1, -1);
        sort(nums.begin(), nums.end());
        // dp[0] =1;
        // for(int i=1;i<=target;i++)
        // {
        //     int count = 0;
        //     for(int j=0;j<nums.size();j++)
        //     {
        //         if(nums[j]<=i)
        //             count += dp[i-nums[j]];
        //     }
        //     dp[i] = count;
        // }
        // return dp[target];
        
        return solve(nums,target, dp);
    }
};