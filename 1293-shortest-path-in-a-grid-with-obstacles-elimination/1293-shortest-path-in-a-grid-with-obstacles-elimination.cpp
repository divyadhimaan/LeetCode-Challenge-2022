class Solution {
public:
    
    bool isValid(vector<vector<int>> &grid, int i, int j)
    {
        if(i<0 || i>=grid.size() || j<0 || j>=grid[0].size())
            return false;
        return true;
    }
    
    vector<pair<int,int>> d = {{1,0}, {-1,0}, {0,1}, {0,-1}};
    
    int shortestPath(vector<vector<int>>& grid, int k) {
        int row = grid.size();
        int col = grid[0].size();
        
        // row-col-steps-k
        queue<vector<int>> q;
        q.push({0,0,0,k});
        
        // vis vector will store the k value
        vector<vector<int>> vis(row, vector<int>(col,-1));
        
        while(!q.empty())
        {
            auto t = q.front();
            q.pop();
            
            int x = t[0];
            int y = t[1];
            int s = t[2];
            int nk = t[3];
            
            if(x==row-1 && y==col-1)
                return s;
            
            if(grid[x][y] == 1){
                if(nk>0)
                    nk--;
                else
                    continue;
            }
            if(vis[x][y] != -1 && vis[x][y] >= nk)
                continue;
            vis[x][y] = nk;
            
            for(auto it: d)
            {
                int nx = x + it.first;
                int ny = y + it.second;
                
                if(isValid(grid, nx, ny))
                    q.push({nx,ny,s+1, nk});
            }
            
        }
        return -1;
    }
};