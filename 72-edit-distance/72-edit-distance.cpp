class Solution {
public:
    
    int solve(string s1, string s2, int m, int n)
    {
        if(m==0)
            return n;
        if(n==0)
            return m;
        
        if(s1[m-1]== s2[n-1])
            return solve(s1, s2, m-1, n-1);
        else
            return 1 + min(solve(s1, s2, m, n-1),min(solve(s1, s2, m-1, n), solve(s1, s2, m-1, n-1)));
    }
    
    int minDistance(string word1, string word2) {
        int m = word1.length();
        int n = word2.length();
        
        vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
        for(int i=0;i<=n;i++)
        {
            dp[0][i] = i;
        }
        for(int i=0;i<=m;i++)
        {
            dp[i][0] = i;
        }
        for(int i=1;i<=m;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(word1[i-1]== word2[j-1])
                    dp[i][j] =  dp[i-1][j-1];
                else
                    dp[i][j] =  1 + min(dp[i][j-1],min(dp[i-1][j], dp[i-1][j-1]));
            }
        }
        
        return dp[m][n];
    }
};