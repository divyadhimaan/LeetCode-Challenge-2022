
class Solution {
public:
    
    int DFS(vector<vector<int>>& obstacleGrid, int i, int j, vector<vector<int>> &memo)
    {
        if(i<0 || i>=obstacleGrid.size() || j<0 || j>= obstacleGrid[0].size())
            return 0;
        
        if(obstacleGrid[i][j] == 1)
            return 0;
        if(memo[i][j] != -1)
            return memo[i][j];
        
        if(i == obstacleGrid.size()-1 && j==obstacleGrid[0].size()-1 && obstacleGrid[i][j]==0)
            return 1;
        
        return memo[i][j] = DFS(obstacleGrid, i+1, j, memo) + DFS(obstacleGrid, i, j+1, memo);
        
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
        
        dp[0][1] = 1;
        
        for(int i=1;i<=m;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(!obstacleGrid[i-1][j-1] )
                    dp[i][j] =dp[i-1][j] + dp[i][j-1];
                else
                    dp[i][j] = 0;
            }
        }
        
        return dp[m][n];
    }
};