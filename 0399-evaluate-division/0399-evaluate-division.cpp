class Solution {
public:
    unordered_map<string, vector<pair<string, double>>> adj;
    unordered_map<string, bool> visited;
    double res;
    
    bool findPath(string s, string d, double ans)
    {
        if(adj.find(s) == adj.end() || adj.find(d) == adj.end())
            return false;
        
        if(s == d)
        {
            res = ans;
            return true;
        }
        
        bool temp = false;
        visited[s] = true;
        for(auto v: adj[s])
        {
            if(!visited[v.first])
            {
                temp = findPath(v.first, d, ans * v.second);
                
                if(temp)
                    break;
            }
            
            
        }
        visited[s] = false;
        return temp;
    }
    
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_map<string, pair<string, int>> mp;
        
        for(int i=0;i<equations.size();i++)
        {
            string source = equations[i][0];
            string destination = equations[i][1];
            adj[source].push_back({destination, values[i]});
            adj[destination].push_back({source, 1/values[i]});
            
            visited[source] = false;
            visited[destination] = false;
        }
        
        vector<double> ans;
        for(auto query: queries)
        {
            res = 1;
            if(!visited[query[0]])
            {
                if(findPath(query[0], query[1], 1))
                    ans.push_back(res);
                else
                    ans.push_back(-1);
            }
        }
        
        return ans;
        
    }
};