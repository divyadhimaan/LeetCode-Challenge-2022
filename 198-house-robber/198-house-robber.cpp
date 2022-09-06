class Solution {
public:
    
    int solve(vector<int> &nums, int n, vector<int> &memo)
    {
        // if(n==0 ||n==1)
        //     return nums[n];
        
        if(n<0)
            return 0;
        
        if(memo[n]!=-1)
            return memo[n];
        
        int pick = nums[n] + solve(nums, n-2, memo);
        int not_pick = solve(nums, n-1, memo);
        
        return memo[n] = max(pick,not_pick);
    }
    
    int rob(vector<int>& nums) {
        vector<int> memo(nums.size(), -1);
        return solve(nums, nums.size()-1, memo);
    }
};