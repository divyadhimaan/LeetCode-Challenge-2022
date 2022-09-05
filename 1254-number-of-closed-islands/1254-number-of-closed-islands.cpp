class Solution {
public:
    
    bool DFS(vector<vector<int>> &grid, int i, int j)
    {
        if(i<0 || i>=grid.size() || j<0 || j>= grid[0].size())
            return false;
        
        if(grid[i][j]==1)
            return true;
        
        grid[i][j]=1;
        
        bool a = DFS(grid, i+1, j);
        bool b = DFS(grid, i, j+1);
        bool c = DFS(grid, i-1, j);
        bool d = DFS(grid, i, j-1);
        
        return a && b && c && d; 

        
    }
    
    int closedIsland(vector<vector<int>>& grid) {
        
        int res = 0;
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[0].size();j++)
            {
                if(grid[i][j]==0)
                    if(DFS(grid, i, j))
                        res++;
            }
        }
        return res;
        
        
    }
};