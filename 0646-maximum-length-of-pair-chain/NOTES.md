DP SOLUTION
​
TC ->O(n^2)
SC -> O(n)
```
int findLongestChain(vector<vector<int>>& pairs) {
sort(pairs.begin(), pairs.end());
vector<int> dp(pairs.size(),1);
for(int i=1;i<pairs.size();i++)
{
for(int j=0;j<i;j++)
{
if(pairs[j][1] < pairs[i][0])
dp[i] = max(dp[i], dp[j]+1);
}
}
return *max_element(dp.begin(), dp.end());
}
```
​
​
GREEDY APPROACH
​
TC ->  o(nlogn)
SC -> O(1)
```
int findLongestChain(vector<vector<int>>& pairs) {
sort(pairs.begin(), pairs.end());
int curr = INT_MIN, ans=0;
for(int i=0;i<pairs.size();i++)
{
if(curr < pairs[i][0])
{
curr = pairs[i][1];
ans++;
}
}
return ans;
}
```