class Solution {
public:
    const static int N = 100001;
    vector<int> adj[N];
    bool visited[N];
    
    void DFS(string &s, int vertex, vector<int> &indices, vector<char> &characters)
    {
        indices.push_back(vertex);
        characters.push_back(s[vertex]);
        
        visited[vertex] = true;
        
        for(int adjacent: adj[vertex])
        {
            if(!visited[adjacent])
                DFS(s, adjacent, indices, characters);
        }
    }
    
    
    
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        for(vector<int> edge: pairs)
        {
            int source = edge[0];
            int destination = edge[1];
            
            adj[source].push_back(destination);            
            adj[destination].push_back(source);

        }
        
        
        for(int vertex = 0; vertex< s.size(); vertex++)
        {
            vector<int> indices;
            vector<char> characters;
            if(!visited[vertex])
            {
                
                
                
                DFS(s, vertex, indices, characters);
                
                
                sort(characters.begin(), characters.end());                
                sort(indices.begin(), indices.end());
                
                
                for(int idx=0; idx<characters.size(); idx++)
                {
                    s[indices[idx]] = characters[idx];
                }

            }
        }
        return s;
    }
};