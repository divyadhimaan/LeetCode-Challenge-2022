​
```
class Solution {
public:
int lcs(vector<int>& nums1, vector<int>& nums2, int m, int n,vector<vector<int>> &memo)
{
if(memo[m][n] != -1)
return memo[m][n];
if(m==0 || n==0)
memo[m][n] = 0;
else {
if(nums1[m-1] == nums2[n-1])
memo[m][n] =  1 + lcs(nums1, nums2, m-1, n-1, memo);
else
memo[m][n] = max(lcs(nums1, nums2, m-1, n, memo), lcs(nums1, nums2, m, n-1, memo));
}
return memo[m][n];
}
int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
vector<vector<int>> memo(nums1.size(), vector<int>(nums2.size(), -1));
return lcs(nums1, nums2, nums1.size(), nums2.size(), memo);
}
};
```
​
Tabulation Approach
​
```
​
```