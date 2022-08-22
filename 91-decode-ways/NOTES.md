return 1;
int count=0;
if(s[i] != '0')
count += ways(s,i+1);
if(i+1 < s.length() && (s[i] == '1' || (s[i] == '2' && s[i+1] <='6')))
count += ways(s,i+2);
return count;
}
int numDecodings(string s) {
return ways(s,0);
}
};
```
​
​
DP Memoization (Top Down Approach)
​
```
class Solution {
public:
int ways(string s, int i, vector<int> &memo)
{
if(i==s.length())
return 1;
if(memo[i] != -1)
return memo[i];
int count=0;
if(s[i] != '0')
count += ways(s,i+1,memo);
if(i+1 < s.length() && (s[i] == '1' || (s[i] == '2' && s[i+1] <='6')))