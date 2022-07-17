class Solution {
public:
    
    bool isSafe(vector<vector<int>>& grid, vector<vector<bool>> &vis, int i, int j)
    {
        if(i<0 || j<0 || i>=grid.size() || j>=grid[0].size() || vis[i][j] || grid[i][j]==0)
            return false;
        
        return true;
    }
    
    void DFS(vector<vector<int>>& grid, vector<vector<bool>> &vis, int i, int j)
    {
        
        vis[i][j] = true;
        
        if(isSafe(grid, vis, i-1, j))
        {
            count++;
            DFS(grid, vis, i-1, j);
        }
        
        if(isSafe(grid, vis, i+1, j))
        {
            count++;
            DFS(grid, vis, i+1, j);
        }
        
        if(isSafe(grid, vis, i, j-1))
        {
            count++;
            DFS(grid, vis, i, j-1);
        }
        
        if(isSafe(grid, vis, i, j+1))
        {
            count++;
            DFS(grid, vis, i, j+1);
        }

    }
    
    int count;
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        
        int maxx = 0;
        
        vector<vector<bool>> vis(grid.size(), vector<bool>(grid[0].size(), false));
        
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[0].size();j++)
            {
                if(!vis[i][j] && grid[i][j]==1)
                {
                    count = 1;
                    DFS(grid, vis, i, j);
                    maxx = max(maxx, count);
                }
                
            }
        }
        return maxx;
    }
};