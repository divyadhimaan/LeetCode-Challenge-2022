class Solution {
public:
    int mod = 1e9 + 7;
    long long solve(int i, vector<long long> &memo)
    {
        if(i==0)
            return 2;
        if(i==1)
            return 3;
        
        if(memo[i] != -1)
            return memo[i];
        
        return memo[i] = (solve(i-2, memo) + solve(i-1, memo))%mod;
    }
    
    int countHousePlacements(int n) {
        vector<long long> memo(n, -1);
        long long temp = (solve(n-1, memo));
        return (temp*temp)%mod;
    }
};