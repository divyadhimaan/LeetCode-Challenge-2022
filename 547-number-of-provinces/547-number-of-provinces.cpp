class Solution {
public:
    void DFS(vector<vector<int>>& isConnected, vector<bool> &vis, int i)
    {
        vis[i] = true;
        
        for(int j=0;j<isConnected.size();j++)
        {
            if(!vis[j] && isConnected[i][j] == 1)
                DFS(isConnected, vis,j);
        }
    }
    
    
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<bool> vis(n, false);
        
        int provinces = 0;
        for(int i=0;i<n;i++)
        {
            if(!vis[i]){
                DFS(isConnected, vis, i);
                provinces++;
            }
        }
        
        return provinces;
    }
};