vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
vector<double> ans;
for(int i=0;i<equations.size();i++)
{
vector<string> pair = equations[i];
string source = pair[0];
string destination = pair[1];
adj[source].push_back({destination, values[i]});                                               adj[destination].push_back({source, (1/values[i])});
visited[source] = false;
visited[destination] = false;
​
}
// for(auto &x: adj)
// {
//     cout<<x.first<<" -> ";
//     for(int i=0;i<x.second.size();i++)
//         cout<<x.second[i].first<<" "<<x.second[i].second<<", ";
//     cout<<endl;
// }
for(int i=0;i<queries.size();i++)
{
vector<string> query = queries[i];
res=1;
if(!visited[query[0]])
{
visited[query[0]] = true;
double res = findPath(query[0], query[1]);
ans.push_back(res);
}
pq = priority_queue <pair<double,string>>();
​
}
return ans;
}
};
```