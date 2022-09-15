class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        
        vector<bool> visited(n, false);
        queue<int> q;
        q.push(0);
        visited[0] = true;
        
        int count=n;
        while(!q.empty())
        {
            int size=q.size();
            for(int i=0;i<size;i++)
            {
                int curr = q.front();
                q.pop();
                // visited[curr] = true;
                count--;
                
                for(int j=0;j<rooms[curr].size();j++)
                {
                    if(visited[rooms[curr][j]]==false){
                        visited[rooms[curr][j]] = true;
                        q.push(rooms[curr][j]);
                    }
                }
            }
        }
        return count==0;
    }
};