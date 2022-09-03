class Solution {
public:
    vector<int> dx = {-1,0, 1, 0};
    vector<int> dy = {0, 1, 0, -1};
    
    
    bool isValid(vector<vector<int>>& grid, int i, int j)
    {
        if(i<0 ||i >=grid.size() || j<0 || j>= grid[0].size())
            return false;
        return true;
    }
    
    int orangesRotting(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        
        queue<pair<int,int>> q;
        
        int fresh=0;
        for(int i=0;i<row;i++)
        {
            for(int j=0;j<col;j++)
            {
                if(grid[i][j] == 2)
                    q.push({i,j});
                else if(grid[i][j]==1)
                    fresh++;
            }
        }
        
        int time = -1;
        while(!q.empty())
        {
            
            int size = q.size();
            for(int i=0;i<size;i++)
            {
                auto t = q.front();
                q.pop();

                int x = t.first;
                int y = t.second;

                for(int k=0;k<4;k++)
                {
                    int nx = x + dx[k];
                    int ny = y + dy[k];

                    if(isValid(grid, nx, ny) && grid[nx][ny] == 1)
                    {
                        grid[nx][ny] = 2;
                        fresh--;
                        q.push({nx, ny});
                    }
                }
            }
            
            time += 1;
        }
        if(fresh>0)
            return -1;
        if(time==-1)
            return 0;
        return time;
    }
};