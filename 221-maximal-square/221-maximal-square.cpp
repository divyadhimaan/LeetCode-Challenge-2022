class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        
        int m = matrix.size();
        int n = matrix[0].size();
        
        vector<vector<int>> dp(m, vector<int> (n));
        
        
        for(int i=0;i<m;i++)
        {
            dp[i][0] = matrix[i][0]-'0';
        }
        
        for(int j=0;j<n;j++)
        {
            dp[0][j] = matrix[0][j]-'0';
        }
        
        int maxi = 0;
        for(int i=1;i<m;i++)
        {
            for(int j=1;j<n;j++)
            {
                if(matrix[i][j]== '0')
                    dp[i][j] = 0;
                
                else{
                    dp[i][j] = 1 + min(dp[i-1][j], min(dp[i-1][j-1], dp[i][j-1]));
                }
            }
        }
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                maxi = max(maxi, dp[i][j]);
            }
        }
        return pow(maxi,2);
    }
};