class Solution {
public:
    int eD(string s1, string s2, int m, int n)
    {
        if(m==0)
            return n;
        if(n==0)
            return m;
        if(s1[m-1] == s2[n-1])
            return eD(s1, s2, m-1, n-1);
        else 
            return 1 + min(eD(s1, s2, m, n-1), min(eD(s1, s2, m-1, n), eD(s1, s2, m-1, n-1)));
    }
    
    int eD2(string s1, string s2, int m, int n)
    {
        vector<vector<int>> dp(m+1, vector<int>(n+1));
        
        int j=0;
        for(int i=0;i<=m;i++)
            dp[i][0] = j++;
        
        int i=0;
        for(int j=0;j<=n;j++)
            dp[0][j] = i++;
        
        for(int i=1;i<=m;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(s1[i-1] == s2[j-1])
                    dp[i][j] = dp[i-1][j-1];
                else
                    dp[i][j] = 1 + min(dp[i-1][j], min(dp[i-1][j-1], dp[i][j-1]));
            }
        }
        return dp[m][n];
        // return 1 + min(eD(s1, s2, m, n-1), min(eD(s1, s2, m-1, n), eD(s1, s2, m-1, n-1)));
    }
    
    int minDistance(string word1, string word2) {
        return eD2(word1, word2, word1.length(), word2.length());
    }
};