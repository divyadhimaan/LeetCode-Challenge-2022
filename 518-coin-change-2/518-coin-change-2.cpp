class Solution {
public:
    
    int coinCh(vector<int> &coins, int n, int amount, vector<vector<int>> &memo)
    {
        if(amount==0)
            return 1;
        if(n==0)
            return 0;
        
        if(memo[amount][n-1]!=-1)
            return memo[amount][n-1];
        
        int res = coinCh(coins, n-1, amount, memo);
        if(coins[n-1] <= amount)
            res += coinCh(coins, n, amount- coins[n-1], memo);
        
        return memo[amount][n-1] = res;
    }
    
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>> memo(amount+1,vector<int>(n+1, -1));
        
        return coinCh(coins, n, amount, memo);
    }
};