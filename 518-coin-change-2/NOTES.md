}
return dp[amount][n];
}
int change(int amount, vector<int>& coins) {
return coinChange(coins, coins.size(), amount);
}
};
```
​
Top Up DP Approach
```
class Solution {
public:
vector<vector<int>> dp;
int coinChange(vector<int> &coins, int n, int amount)
{
if(amount == 0)
dp[amount][n] = 1;
if(n == 0)
dp[amount][n] = 0;
if(dp[amount][n] != -1)
return dp[amount][n];
dp[amount][n] = coinChange(coins, n-1, amount);
if(coins[n - 1] <= amount)
dp[amount][n] += coinChange(coins, n, amount - coins[n - 1]);
return dp[amount][n];
}
int change(int amount, vector<int>& coins) {
dp.resize(amount+1, vector<int>(coins.size() +1, -1));
return coinChange(coins, coins.size(), amount);
}
};
```