class Solution {
public:
    int n,m;
    int solve(vector<int>& nums, vector<int>& multipliers, int i, int j, vector<vector<int>> &memo)
    {
        if(j==multipliers.size())
            return 0;
        
        if(memo[i][j] != INT_MIN)
            return memo[i][j];
        
        int pickFirst = nums[i]*multipliers[j] + solve(nums, multipliers, i+1, j+1, memo);
        int pickLast = nums[(n-1) - (j-i)]*multipliers[j] + solve(nums, multipliers, i, j+1, memo);
        int score = max(pickFirst, pickLast);
        
        return memo[i][j] = score;
    }
    
    int maximumScore(vector<int>& nums, vector<int>& multipliers) {
        n = (int) nums.size();
        m = (int) multipliers.size();
        
        vector<vector<int>> memo(m, vector<int>(m, INT_MIN));
        return solve(nums, multipliers,0,0, memo);
    }
};