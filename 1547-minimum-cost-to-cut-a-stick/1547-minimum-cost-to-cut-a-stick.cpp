class Solution {
public:
    int mod = 1e9 + 7;
    int solveCost(vector<int> &cuts, int i, int j, vector<vector<int>> &memo)
    {
        if(i>j)
            return 0;
        
        if(memo[i][j] != -1)
            return memo[i][j];
        
        int miniCost = INT_MAX;
        for(int idx = i; idx<=j; idx++)
        {
            int cost = (cuts[j+1] - cuts[i-1]) + solveCost(cuts, i, idx-1, memo) + solveCost(cuts, idx+1, j, memo);
            miniCost = min(miniCost, cost);
        }
        return memo[i][j] = miniCost;
    }
    
    int minCost(int n, vector<int>& cuts) {
        int c = cuts.size();
        
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