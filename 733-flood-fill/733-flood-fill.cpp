class Solution {
public:
    vector<int> dx = {1,-1,0,0};
    vector<int> dy = {0,0,-1,1};
    
    bool isValid(vector<vector<int>>& image, int i, int j, vector<vector<bool>> &vis, int req)
    {
        if(i<0 || i>= image.size() || j<0 || j>=image[0].size() || vis[i][j] || image[i][j] != req)
            return false;
        return true;
    }
    
    void DFS(vector<vector<int>>& image, int i, int j, vector<vector<bool>> &vis, int req, int color)
    {
        vis[i][j] = true;
        image[i][j] = color;
        for(int k=0;k<4;k++)
        {
            int x = i + dx[k];
            int y = j + dy[k];
            
            if(isValid(image, x,y, vis, req)){
                 
                DFS(image, x, y, vis, req, color);
            }
        }
    }
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int r = image.size();
        int c = image[0].size();
        vector<vector<bool>> vis(r, vector<bool>(c, false));
        
        for(int i=0;i<r;i++)
        {
            for(int j=0;j<c;j++)
            {
                if(i == sr && j==sc && !vis[i][j])
                    DFS(image, i, j, vis, image[i][j], color);
            }
        }
        
        return image;
    }
};