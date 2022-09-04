class Solution {
public:
    vector<int> dir={0,1,-1};
    int pickup(vector<vector<int>>& grid, int i, int j1, int j2, int row, int col, vector<vector<vector<int>>> &memo)
    {
        if(i<0 || i>= row || j1<0 || j1>= col || j2<0 || j2>=col)
            return 0;
        
        
        if(i==row-1)
        {
            if(j1 == j2)
            {
                return grid[i][j1];
                
            }else{
                return grid[i][j1] + grid[i][j2];
            }
        }
        
        if(memo[i][j1][j2]!=-1)
            return memo[i][j1][j2];
        
        int ans = 0;
        for(int x: dir)
        {
            for(int y: dir)
            {
                int a = 0;
                int ni = i + 1;
                int nj1 = j1 + x;
                int nj2 = j2 + y;
                if(j1 == j2)
                {
                    a = grid[i][j1] + pickup(grid, ni, nj1, nj2, row, col, memo);
                }else{
                    a = grid[i][j1] + grid[i][j2] +pickup(grid, ni, nj1, nj2, row, col, memo); 
                }
                ans = max(ans, a);        
            }
        } 
        return memo[i][j1][j2] = ans;
    }
    
    int cherryPickup(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        
        vector<vector<vector<int>>> dp(row, vector<vector<int>>(col, vector<int>(col, INT_MIN)));
        
        
        for(int j1=0;j1<col;j1++)
        {
            for(int j2=0;j2<col;j2++)
            {
                if(j1 == j2)
                {
                    dp[row-1][j1][j2] = grid[row-1][j1];

                }else{
                    dp[row-1][j1][j2] = grid[row-1][j1] + grid[row-1][j2];
                }
            }
        }
        
        for(int i=row-2;i>=0;i--)
        {
            for(int j1=0;j1<col;j1++)
            {
                for(int j2=0;j2<col;j2++)
                {
                    int ans = 0;
                    for(int x: dir)
                    {
                        for(int y: dir)
                        {
                            int a = 0;
                            int ni = i + 1;
                            int nj1 = j1 + x;
                            int nj2 = j2 + y;
                            if(ni<0 || ni>= row || nj1<0 || nj1>= col || nj2<0 || nj2>=col)
                                continue;
                            if(j1 == j2)
                            {
                                a = grid[i][j1] + dp[ni][nj1][nj2];
                            }else{
                                a = grid[i][j1] + grid[i][j2] +dp[ni][nj1][nj2]; 
                            }
                            ans = max(ans, a);        
                        }
                    } 
                    dp[i][j1][j2] = ans;
                }
            }
        }
        
        return dp[0][0][col-1];
    }
};