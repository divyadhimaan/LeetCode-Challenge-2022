class Solution {
public:
    vector<vector<int>> dp;
    int lcs(string &text1, string &text2, int m, int n)
    {
        if(dp[m][n] != -1)
            return dp[m][n];
        
        if(m==0 || n==0){
            
            dp[m][n]=0;
        }
            
        else{
            if(text1[m-1] == text2[n-1])
                dp[m][n] = 1 + lcs(text1, text2, m-1, n-1);
            else
                dp[m][n] = max(lcs(text1, text2, m-1, n), lcs(text1, text2, m, n-1));
        }
        return dp[m][n];
    }
    
    
    int longestCommonSubsequence(string text1, string text2) {
        
        dp.resize(1001, vector<int> (1001,-1));
        
        return lcs(text1, text2, text1.length(), text2.length());
    }
};