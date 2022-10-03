class Solution {
public:
    
    void DFS(vector<vector<int>>& isConnected, vector<bool> &vis, int u)
    {
        vis[u] = true;
        
        for(int i=0;i<isConnected.size();i++)
        {
            if(!vis[i] && isConnected[u][i] == 1)
                DFS(isConnected, vis, i);
        }
    }
    
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<bool> vis(n, false);
        
        int provinces=0;
        for(int i=0;i<n;i++)
        {
            if(!vis[i])
            {
                DFS(isConnected, vis, i);
                provinces++;
            }
        }
        return provinces;
    }
};