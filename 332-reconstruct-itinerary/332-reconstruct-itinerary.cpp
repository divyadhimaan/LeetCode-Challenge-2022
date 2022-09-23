class Solution {
public:
    unordered_map<string, priority_queue<string, vector<string>, greater<string>>> graph;
    vector<string> ans;
    
    void DFS(string u)
    {
        auto &edge = graph[u];
        
        while(!edge.empty())
        {
            string v = edge.top();
            edge.pop();
            DFS(v);
        }
        ans.push_back(u);
    }
    
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        for(auto t: tickets)
        {
            graph[t[0]].push(t[1]);
        }
        
        DFS("JFK");
        reverse(ans.begin(), ans.end());
        return ans;
    }
    
};