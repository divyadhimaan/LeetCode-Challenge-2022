class Solution {
public:
    int dx[4] = {-1,1,0,0};
    int dy[4] = {0,0,-1,1};
    
    bool isValid(int idx, int lim)
    {
        if(idx>=0 && idx<lim)
            return true;
        return false;
    }
    void solve(vector<vector<char>>& board) {
        
        int m = board.size();
        int n = board[0].size();
        vector<vector<bool>> vis(m, vector<bool> (n, false));
        
        queue<pair<int,int>> q;
        
        for(int i=0;i<n;i++){
            if(board[0][i]=='O'){
                vis[0][i] = true;
                q.push({0,i});
            }
        }
        
        for(int i=0;i<n;i++){
            if(board[m-1][i]=='O'){
                vis[m-1][i] = true;
                q.push({m-1,i});
            }
        }
        
        for(int i=0;i<m;i++){
            if(board[i][0]=='O'){
                vis[i][0] = true;
                q.push({i,0});
            }
        }
        
        for(int i=0;i<m;i++){
            if(board[i][n-1]=='O'){
                vis[i][n-1] = true;
                q.push({i,n-1});
            }
        }
        
        // while(!q.empty())
        // {
        //     pair<int,int> p = q.front();
        //     q.pop();
        //     cout<<p.first<<" "<<p.second<<endl;
        // }
        
        while(!q.empty())
        {
            for(int i=0;i<q.size();i++)
            {
                pair<int,int> curr = q.front();
                q.pop();
                
                int x = curr.first;
                int y = curr.second;
                
                for(int k=0;k<4;k++)
                {
                    int i = x+dx[k];
                    int j = y+dy[k];
                    
                    if(isValid(i,m) && isValid(j, n) && board[i][j] == 'O' && vis[i][j]==false)
                    {
                        vis[i][j] = true;
                        q.push({i,j});
                    }
                }
            }
        }
        
        for(int i=0;i<m;i++)
        {
            for(int j =0;j<n;j++)
            {
                if(board[i][j] == 'O' && vis[i][j]==false)
                    board[i][j] = 'X';
            }
        }
    }
};