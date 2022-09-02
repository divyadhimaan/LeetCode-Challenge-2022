class Solution {
public:
    
    bool isValid(vector<vector<int>> &grid, int i, int j)
    {
        if(i<0 || i>=grid.size() || j<0 || j>=grid[0].size())
            return false;
        return true;
    }
    
    
    vector<pair<int,int>> d = {{1,0}, {-1,0}, {0,1}, {0,-1}};
    int minimumObstacles(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        
        vector<vector<int>> dp(row, vector<int>(col, INT_MAX));
        dp[0][0] = 0;
        queue<pair<int,int>> q;
        q.push({0,0});
        
        while(!q.empty())
        {
            int size = q.size();
            for(int i=0;i<size;i++)
            {
                int x = q.front().first;
                int y = q.front().second;
                q.pop();
                
                for(auto it: d)
                {
                    int nx = x + it.first;
                    int ny = y + it.second;
                    
                    if(isValid(grid, nx, ny) && dp[nx][ny] > dp[x][y] + grid[nx][ny])
                    {
                        dp[nx][ny] = dp[x][y] + grid[nx][ny];
                        q.push({nx,ny});
                    }
                }
            }
        }
        return dp[row-1][col-1];
    }
    
    
};