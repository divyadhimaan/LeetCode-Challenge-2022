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
        
        vector<vector<vector<int>>> memo(row, vector<vector<int>>(col, vector<int>(col, -1)));
        int i=0, j1 = 0, j2 = col-1;
        return pickup(grid, i, j1, j2, row, col, memo);
        
    }
};