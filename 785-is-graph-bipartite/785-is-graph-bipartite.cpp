class Solution {
public:
    bool BFS(vector<vector<int>> &graph,bool visited[], int vertex)
    {
        queue<int> q;
        q.push(vertex);
        
        visited[vertex] = true;
        
        vector<int> color(graph.size(),-1);
        
        while(!q.empty())
        {
            int u = q.front();
            q.pop();
            
            vector<int> x = graph[u];
            if(color[u] == -1)
                color[u] = 1;
            
            for(int i=0;i<x.size();i++)
            {
                if(!visited[x[i]])
                {
                    q.push(x[i]);
                    visited[x[i]] = true;
                }
                
                if(color[x[i]]==-1)
                    color[x[i]] = !color[u];
                else
                    if(color[x[i]] == color[u])
                        return false;
            }
        }
        return true;
    }
    
    bool isBipartite(vector<vector<int>>& graph) {
        int V = graph.size();
        bool visited[V];
        bool is_bipartite = true;
        
        for(int i=0;i<V;i++)
            visited[i] = false;
        
        for(int i=0;i<V;i++)
        {
            if(!visited[i])
                is_bipartite = BFS(graph,visited,i);
                if(!is_bipartite)
                    return false;
        }
        return true;
    }
};