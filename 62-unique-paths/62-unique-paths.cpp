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
        vector<vector<int>> memo(m, vector<int>(n,-1));
        return paths(m-1,n-1, memo);
        
    }
};