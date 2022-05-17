class Solution {
public:
    int dx[8] = {1,0,-1,0,1,-1,-1,1};
    int dy[8] = {0,1,0,-1,1,1,-1,-1};
    
    bool isValid(int index,int lim){
        if(index>=0 && index<lim){
            return true;
        }else{
            return false;
        }
    }
    
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        
        
        if(grid[0][0]==1){
            return -1;
        }
        int n = grid.size();
        vector<vector<int>> dist(n,vector<int>(n,0));
        queue<pair<int,int>> q;
        q.push({0,0});
        dist[0][0] = 1;
        grid[0][0] = 1;
    
        
        while(!q.empty()){
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            if(x==n-1 && y==n-1){
                return dist[x][y];
            }
             for(int k=0;k<8;k++){
                int i = x+dx[k];
                int j = y+dy[k];
                if(isValid(i,n) && isValid(j,n)){
                    if(grid[i][j]==0){
                        dist[i][j] = dist[x][y] + 1;
                        grid[i][j] = 1;
                        q.push({i,j});
                    }
                    
                }
            }
        }
        return -1;
       
        
    }
};