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