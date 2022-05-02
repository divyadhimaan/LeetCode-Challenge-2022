class Solution {
public:
    unordered_map<string, vector<pair<string,double>>> adj;
    double res;
    unordered_map<string, bool> visited;
    
    
    bool findPath(string s, string d, double ans)
    {
        if(adj.find(s)== adj.end() || adj.find(d)==adj.end())
            return false;
    
        if(s==d){
            res = ans;
            return true;
        }
            
        
        vector<pair<string,double>> q = adj[s];
        
        bool temp = false;
        visited[s] = true;
        
        for(int i=0;i<q.size();i++)
        {
            if(!visited[q[i].first])
            {
                // res *= q[i].second;
                
                temp = findPath(q[i].first, d, ans * q[i].second);
                if(temp)
                    break;
            }       
        }
        visited[s] = false;

        return temp;
    }
    
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        
        vector<double> ans;
        
        for(int i=0;i<equations.size();i++)
        {
            vector<string> pair = equations[i];
            string source = pair[0];
            string destination = pair[1];
            
            adj[source].push_back({destination, values[i]});                                               adj[destination].push_back({source, (1/values[i])});
            visited[source] = false;
            visited[destination] = false;

        }
        
        for(int i=0;i<queries.size();i++)
        {
            vector<string> query = queries[i];
            res = 1;
            if(!visited[query[0]])
            {
                bool temp = findPath(query[0], query[1],1);
                
                if(temp)
                    ans.push_back(res);
                else
                    ans.push_back(-1);
            }

        }
        return ans;
    }
};