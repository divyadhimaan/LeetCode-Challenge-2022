class Solution {
public:
    
//     int solve(vector<int> &coins, int n, int amount)
//     {
//         if(amount==0)
//             return 0;
        
//         int res = INT_MAX;
//         for(int i=0;i<coins.size();i++)
//         {
//             if(coins[i] <= amount)
//             {
//                 int subres = solve(coins, n, amount-coins[i]);
//                 if(subres != INT_MAX)
//                     res = min(res, subres+1);
//             }
//         }
//         if(res == INT_MAX)
//             return 0;
//         return res;
//     }
    
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
                        dp[i] = min(dp[i],res+1);
                }
            }
        }
        if(dp[amount]==INT_MAX)
            return -1;
        return dp[amount];
    }
};