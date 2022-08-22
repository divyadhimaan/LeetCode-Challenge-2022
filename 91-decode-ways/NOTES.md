* for single digit dp[i] = dp[i+1]
* for two digits dp[i] = dp[i+2]
* return dp[0]
​
```
class Solution {
public:
int numDecodings(string s) {
int n = s.length();
vector<int> dp(n+1, 0);
​
dp[n] = 1;
for(int i=n-1;i>=0;i--)
{
if(s[i] != '0')
dp[i] += dp[i+1];
if(i+1 < s.length() && (s[i] == '1' || (s[i] == '2' && s[i+1] <='6')))
dp[i] += dp[i+2];
}
return dp[0];
}
};
​
```
​
Time Complexity: O(n)
Space Complexity: O(n)
​
​