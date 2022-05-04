// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    
    
    //approach: bfs -> instead of true/false store the parent node of every node
    bool bfs(int node, vector<int> adj[], vector<int> &visited, int p)
    {
        queue<int> q;
        q.push(node);
        visited[node] = p;
        
        while(!q.empty())
        {
            int u = q.front();
            q.pop();
            
            for(auto v: adj[u])
            {
                if(visited[v] == -1)
                {
                    visited[v] = u;
                    q.push(v);
                }else {
                    if(v != visited[u])
                        return true;
                }
            }
        }
        
        return false;
    }
    bool isCycle(int V, vector<int> adj[]) {
        vector<int> visited(V, -1);
        
        for(int i=0;i<V;i++)
        {
            if(visited[i] == -1)
            {
                if(bfs(i,adj,visited, -2))
                    return true;
            }
        }
        return false;   
        
    }
};

// { Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}  // } Driver Code Ends