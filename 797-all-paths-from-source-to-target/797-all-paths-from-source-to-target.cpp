class Solution {
public:
    vector<vector<int>> ans;
    void DFS(vector<vector<int>> &graph, int u, vector<int> &path, vector<bool> &vis,int n)
    {
        vis[u] = true;
        path.push_back(u);
        
        if(u == n-1)
            ans.push_back(path);
        
        for(auto v: graph[u])
        {
            if(!vis[v])
            {
                DFS(graph, v, path, vis, n);
            }
        }
        vis[u] = false;
        path.pop_back();
    }
    
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        
        int n = graph.size();
        vector<bool> vis(n, false);
        vector<int> path;
        
        DFS(graph, 0, path, vis, n);
        return ans;
    }
};