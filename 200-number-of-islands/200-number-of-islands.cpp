class Solution {
public:
    
    bool isValid(vector<vector<char>>& grid, int i, int j, vector<vector<bool>>& vis)
    {
        if(i<0 || i>=grid.size() || j<0 ||j>=grid[0].size() || vis[i][j] || grid[i][j]=='0')
            return false;
        return true;
    }
    
    void DFS(vector<vector<char>>& grid, int i, int j, vector<vector<bool>>& vis)
    {
        vis[i][j] = true;
        
        if(isValid(grid, i, j+1, vis))
        {
            DFS(grid, i, j+1, vis);
        }
        
        if(isValid(grid, i, j-1, vis))
        {
            DFS(grid, i, j-1, vis);
        }
        
        if(isValid(grid, i+1, j, vis))
        {
            DFS(grid, i+1, j, vis);
        }
        
        if(isValid(grid, i-1, j, vis))
        {
            DFS(grid, i-1, j, vis);
        }
    }
    
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m= grid[0].size();
        
        vector<vector<bool>> vis(n, vector<bool>(m, false));
        
        int count=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(!vis[i][j] && grid[i][j]=='1')
                {
                    DFS(grid, i,j, vis);
                    count++;
                }
            }
        }
        return count;
    }
};