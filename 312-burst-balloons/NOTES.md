Memoization
​
```
class Solution {
public:
int solve(vector<int> &nums, int i, int j, vector<vector<int>> &memo)
{
if(i>j)
return 0;
if(memo[i][j] != -1)
return memo[i][j];
int maxi = INT_MIN;
for(int index=i;index<=j;index++)
{
int coins = nums[i-1] * nums[index] * nums[j+1] + solve(nums, i, index-1, memo) + solve(nums, index+1, j, memo);
maxi = max(maxi, coins);
}
return memo[i][j] = maxi;
}
int maxCoins(vector<int>& nums) {
int n = nums.size();
nums.push_back(1);
nums.insert(nums.begin(), 1);
vector<vector<int>> memo(n+1, vector<int> (n+1, -1));
return solve(nums, 1, n, memo);
}
};
```
​
Tabulation