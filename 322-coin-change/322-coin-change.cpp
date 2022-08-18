class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<int> dp(amount+1, INT_MAX);
        
        dp[0] = 0;
        for(int i=1;i<=amount;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(coins[j] <= i)
                {
                    int res = dp[i - coins[j]];
                    if(res != INT_MAX)
                        dp[i] = min(dp[i], res + 1);
                }
            }
        }
        if(dp[amount] == INT_MAX)
            return -1;
        
        return dp[amount];
    }
};