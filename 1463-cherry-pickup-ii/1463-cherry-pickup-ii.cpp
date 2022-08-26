class Solution {
public:
    bool isValid(vector<vector<int>> &grid,int j1,int j2)
    {
        
        if(j1<0 || j2<0 || j1>= grid[0].size() || j2>=grid[0].size())
            return false;
        return true;
    }
    
    int solve(vector<vector<int>> &grid, int i, int j1, int j2, int m, vector<vector<vector<int>>> &memo)
    {
        if(!isValid(grid, j1, j2))
            return - 1e5;
            
        if(i==m-1)
        {
            if(j1 == j2)
                return grid[i][j1];
            else
                return grid[i][j1] + grid[i][j2];
        }
        
        if(memo[i][j1][j2] != -1)
            return memo[i][j1][j2];
            
        int ans = -1e5;
        for(int j=-1;j<=1;j++)
        {
            for(int k = -1;k<=1;k++)
            {
                int a =0;
                if(j1 == j2)
                    a = grid[i][j1] + solve(grid, i+1, j1 + j, j2+k, m, memo);
                else
                    a = grid[i][j1] + grid[i][j2] + solve(grid, i+1, j1 + j, j2+k, m, memo);
                
                ans = max(ans, a);
            }

        }
        return memo[i][j1][j2] = ans;
    }
    
    int cherryPickup(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        vector<vector<vector<int>>> memo(m,vector<vector<int>>(n,vector<int>(n, -1)));
        return solve(grid, 0, 0, n-1, m, memo);
    }
};