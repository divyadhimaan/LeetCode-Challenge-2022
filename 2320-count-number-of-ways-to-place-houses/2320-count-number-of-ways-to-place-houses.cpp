class Solution {
public:
    int mod = 1e9 + 7;
    
    int countHousePlacements(int n) {
        
        vector<long long> dp(n,0);
        
        if(n==1)
            return 4;
        // if(n==2)
        //     return 9;
        dp[0] = 2;
        dp[1] = 3;
            
        for(int i=2;i<n;i++)
        {
            dp[i] = (dp[i-1] + dp[i-2])%mod;
        }
        return (dp[n-1]*dp[n-1])%mod;
    }
};