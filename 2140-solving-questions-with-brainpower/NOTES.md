}
long long mostPoints(vector<vector<int>>& questions) {
return solve(questions,0, 0);
}
};
```
​
​
**MEMOIZED APPROACH **
```
class Solution {
public:
long long solve(vector<vector<int>> &ques, int curr, vector<int> &memo)
{
if(curr >= ques.size())
return 0;
if(memo[curr] != 0)
memo[curr];
long long points = ques[curr][0];
memo[curr] = max(points + solve(ques, curr+ques[curr][1]+1, memo), solve(ques, curr+1, memo));
return memo[curr];
}
long long mostPoints(vector<vector<int>>& questions) {
vector<int> memo(questions.size(), 0);
return solve(questions,0, memo);
}
};
```
​
**TABULATION APPROACH**
​
```
long long mostPoints(vector<vector<int>>& ques) {
int n = ques.size();
vector<long long> dp(n);
for(int i=n-1; i>=0; i--)
{
int points = ques[i][0];
int jump = ques[i][1];
dp[i] = max(points + dp[min(i + jump + 1, n)], dp[i+1]);
}
return dp[0];
​
}
```