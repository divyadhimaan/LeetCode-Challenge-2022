Recursive Approach
​
TC ->
```
class Solution {
public:
int coinChange(vector<int> &coins, int n, int amount)
{
if(amount == 0)
return 1;
if(n == 0)
return 0;
int res = coinChange(coins, n-1, amount);
if(coins[n - 1] <= amount)
res += coinChange(coins, n, amount - coins[n - 1]);
return res;
}
int change(int amount, vector<int>& coins) {
return coinChange(coins, coins.size(), amount);
}
};
```
​
Bottom Up Approach
TC -> O(m*n)
SC -> O(m*n)
A better version exists ->  but only space is optimized.
​
```
class Solution {
public:
int coinChange(vector<int> &coins, int n, int amount)
{
vector<vector<int>> dp(amount+1, vector<int>(n+1));
for(int i=0;i<=n;i++)
dp[0][i] = 1;
for(int i=0;i<=amount;i++)
dp[i][0] = 0;