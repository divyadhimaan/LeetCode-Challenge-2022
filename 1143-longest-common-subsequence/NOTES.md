**Naive Approach**
Find all the subsequences of both strings and compare
​
**Recursion Approach**
```
class Solution
{
public:
//Function to find the length of longest common subsequence in two strings.
int lcs(int x, int y, string s1, string s2)
{
if(x == 0 || y==0)
return 0;
if(s1[x-1] == s2[y-1])
return 1 + lcs(x-1, y-1, s1, s2);
else
return max(lcs(x-1, y, s1, s2), lcs(x, y-1, s1, s2));
}
};
```
​
**DP Approach**
Memoization
​
```
class Solution {
public:
vector<vector<int>> dp;