
// #typedef pair<int,int> pii;
class Solution {
public:
//     int mostBooked(int n, vector<vector<int>>& meetings) {
//         sort(meetings.begin(), meetings.end());
        
//         vector<int> occupancy(n, 0);
//         priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        
//         pq.push({meetings[0][0] + meetings[0][1] - meetings[0][0], 0});
//         occupancy[0]++;
//         int room = 1;
//         int time = 0;
        
//         for(int i=1;i<meetings.size();i++)
//         {
//             if(pq.size() < n)
//             {
//                 pq.push({time + meetings[i][0] + (meetings[i][1] - meetings[i][0]), room});
//                 occupancy[room]++;
//                 room++;
//             }  
//             else{
//                 pair<int,int> curr = pq.top();
//                 time = curr.first;
//                 room = curr.second;
//                 while(!pq.empty() && pq.top().first <= time)
//                     pq.pop();
                
                
//                 while(!pq.empty() && meetings[i][0]>pq.top().first){
//                     time += pq.top().first;
//                     pq.pop();
                    
//                 }

//                 if(pq.empty())
//                     room = 0;

//                 occupancy[room]++;

//                 pq.push({time + (meetings[i][1] - meetings[i][0]), room});
//             }
//         }
        
//         int maxi = INT_MIN, index;
//         for(int i=0;i<occupancy.size();i++)
//         {
//             if(occupancy[i]  >maxi)
//             {
//                 maxi = occupancy[i];
//                 index = i;
//             }
//         }
//         return index;
//     }
    int mostBooked(int n, vector<vector<int>>& meets) {
    int cnt[101] = {};
    sort(begin(meets), end(meets));
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
    for (int i = 0; i < n; ++i)
        pq.push({meets[0][0], i});
    for (auto &m : meets) {
        while (pq.top().first < m[0]) {
            pq.push({m[0], pq.top().second});
            pq.pop();
        }
        auto [start, room] = pq.top(); pq.pop();
        pq.push({start + m[1] - m[0], room});
        ++cnt[room];
    }
    return max_element(begin(cnt), end(cnt)) - begin(cnt);
}
};