class Solution {
public:
    const int inf = 1e6+5;
    int dx[2] = {0, 1};    
    int dy[2] = {1, 0};
    
    bool is_valid(int index, int lim)
    {
        return (index>=0 && index<lim);
    }
    
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        priority_queue <pair<int, pair<int,int>>> pq;
        vector<vector<int>> dist(m, vector<int>(n, inf));
        dist[0][0] = grid[0][0];
        pq.push({(-1)*dist[0][0], {0,0}});
        
        while(!pq.empty())
        {
            int distance = (-1) * pq.top().first;
            int x = pq.top().second.first;
            int y = pq.top().second.second;
            pq.pop();
            if(x == m-1 && y == n-1)
                return distance;
            for(int k=0;k<2;k++)
            {
                int i = x + dx[k];
                int j = y + dy[k];
                
                if(is_valid(i,m) && is_valid(j,n))
                { 
                    int sum = distance + grid[i][j];
                    if(sum < dist[i][j])
                    {
                        dist[i][j] = sum;
                        pq.push({(-1)*dist[i][j], {i,j}});
                    }
                }
            }
        }
        return -1;
        
    }
};