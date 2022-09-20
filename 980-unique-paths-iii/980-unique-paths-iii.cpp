class Solution {
public:
    
    vector<int> dx = {-1,1,0,0};
    vector<int> dy = {0,0,1,-1};
    int res=0, empty = 1;
    bool isValid(vector<vector<int>> &grid, int i, int j)
    {
        if(i<0 || i>=grid.size() || j<0 || j>=grid[0].size() || grid[i][j] == -1)
            return false;
        return true;
    }
    
    void DFS(vector<vector<int>> &grid, int i, int j, int count)
    {
        
        if(!isValid(grid,i,j))
            return;
        
        if(grid[i][j] == 2)
        {
            if(empty == count)
                res++;
            return;
        }
      
        grid[i][j] = -1;
        for(int k=0;k<4;k++)
        {
            int ni = i + dx[k];
            int nj = j + dy[k];
            
            DFS(grid, ni, nj, count+1);
        }
        grid[i][j] = 0;
    }
    
    int uniquePathsIII(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        int start_x = 0, start_y=0;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]==1){
                    start_x = i;
                    start_y = j;
                }else if(grid[i][j]==0)
                    empty++;
            }
        }
        
        
        DFS(grid, start_x, start_y, 0);
        return res;
    }
};