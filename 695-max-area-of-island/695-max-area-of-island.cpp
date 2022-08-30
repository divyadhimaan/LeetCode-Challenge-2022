class Solution {
public:
    
    bool isValid(vector<vector<int>>& grid, int i, int j, vector<vector<bool>> &vis)
    {
        if(i<0 || i>= grid.size() || j<0 || j>=grid[0].size() || vis[i][j] || grid[i][j]==0)
            return false;
        return true;
    }
    
    void dfs(vector<vector<int>>& grid, int i, int j, vector<vector<bool>> &vis)
    {
        
        vis[i][j] = true;
        
        if(isValid(grid, i+1, j, vis)){
            count++;
            dfs(grid, i+1, j, vis);
        }
        
        if(isValid(grid, i-1, j, vis)){
            count++;
            dfs(grid, i-1, j, vis);
        }
        
        if(isValid(grid, i, j+1, vis)){
            count++;
            dfs(grid, i, j+1, vis);
        }
        
        if(isValid(grid, i, j-1, vis)){
            count++;
            dfs(grid, i, j-1, vis);
        }
        
    }
    
    int count;
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        vector<vector<bool>> vis(grid.size(), vector<bool> (grid[0].size(),false));
        int max_area = INT_MIN;
        
        
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[0].size();j++)
            {
                if(grid[i][j]==1 && !vis[i][j])
                {
                    count = 1;
                    dfs(grid, i, j, vis);
                    max_area = max(max_area, count);
                }
            }
        }
        if(max_area == INT_MIN)
            return 0;
        return max_area;
    }
};