class Solution {
public:
    int paths(int i,int j, vector<vector<int>> &memo)
    {
        if(i==0 && j==0)
            return memo[i][j] = 1;
        
        if(i<0 || j <0)
            return 0;
        
        if(memo[i][j] != -1)
            return memo[i][j];
        
        return memo[i][j] = paths(i-1,j,memo) + paths(i,j-1,memo);
    }
    
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n,0));

        dp[0][0] = 1;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(i==0 && j==0)
                    continue;
                
                if(i-1 >=0)
                    dp[i][j] += dp[i-1][j];
                if(j-1 >=0)
                    dp[i][j] += dp[i][j-1];
                // dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
        }
        return dp[m-1][n-1];
    }
};