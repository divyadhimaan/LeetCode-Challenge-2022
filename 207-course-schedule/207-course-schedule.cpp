class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adjList(numCourses+1);
        vector<int> inDegree(numCourses, 0);
        
        for(int i=0;i<prerequisites.size();i++)
        {
            adjList[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }
        
        for(int i=0;i<adjList.size();i++)
        {
            for(int j=0;j<adjList[i].size();j++)
                inDegree[adjList[i][j]]++;
        }
        
        queue<int> q;
        for(int i=0;i<inDegree.size();i++)
        {
            if(inDegree[i]==0){
                q.push(i);
            }
        }
        
        while(!q.empty())
        {
            int u = q.front();
            q.pop();
            
            for(auto v: adjList[u])
            {
                inDegree[v]--;
                if(inDegree[v]==0)
                {
                    q.push(v);
                    
                }
            }
            numCourses--;
        }
        
        return numCourses==0;
    }
};