class Solution {
public:
    
    int mod = 1e9 + 7;
    int solve(int m, int n, int maxMove, int i, int j, vector<vector<vector<int>>> &dp)
    {
        if(i == m || j == n || i<0 || j<0)
            return 1;
        
        if(maxMove == 0)
            return 0;
        
        if(dp[i][j][maxMove] != -1)
            return dp[i][j][maxMove];
        
        int left = solve(m, n, maxMove-1, i, j-1, dp);
        int right = solve(m, n, maxMove-1, i, j+1, dp);
        int up = solve(m, n, maxMove-1, i-1, j, dp);
        int down = solve(m, n, maxMove-1, i+1, j, dp);
        
        return dp[i][j][maxMove] = ((left + right)%mod + (up + down)%mod)%mod;
    }
    
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        
        vector<vector<vector<int>>> dp;
        
        dp = vector<vector<vector<int>>>(m, vector<vector<int>>(n, vector<int>(maxMove+1, -1)));
        
        return (solve(m, n, maxMove, startRow, startColumn, dp))%mod;

    }
};