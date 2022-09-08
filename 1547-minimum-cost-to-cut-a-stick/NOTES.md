cuts.push_back(n);
cuts.insert(cuts.begin(), 0);
sort(cuts.begin(), cuts.end());
vector<vector<int>> dp(c+2, vector<int>(c+2, 0));
for(int i=c;i>=1;i--)
{
for(int j= 1; j<=c;j++)
{
if(i>j)
continue;
int miniCost = INT_MAX;
for(int idx = i; idx<=j; idx++)
{
int cost = (cuts[j+1] - cuts[i-1]) + dp[i][idx-1]+ dp[idx+1][j];
miniCost = min(miniCost, cost);
}
dp[i][j] = miniCost;
}
}
return dp[1][c];
}
};
```