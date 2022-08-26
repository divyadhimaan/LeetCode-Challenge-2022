class Solution {
public:
    
    int solve(int f, int e, vector<vector<int>> &memo)
    {
        if(f==0 ||f ==1)
            return f;
        if(e == 1)
            return f;
        
        if(memo[f][e] != -1)
            return memo[f][e];
        
        int mn = INT_MAX;
        for(int i=1;i<=f;i++)
        {
            int temp = max(solve(i-1,e-1, memo), solve(f-i, e, memo));
            mn = min(mn, temp);
            // mn = mn;
        }
        return memo[f][e] = mn+1;
    }
    int twoEggDrop(int f) {
        vector<vector<int>> memo(f+1, vector<int> (3, -1));
        return solve(f, 2, memo);
    }
};