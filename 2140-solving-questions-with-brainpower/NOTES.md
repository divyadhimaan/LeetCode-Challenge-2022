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