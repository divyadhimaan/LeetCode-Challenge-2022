
// #typedef pair<int,int> pii;
class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        sort(meetings.begin(), meetings.end());
        
        vector<int> occupancy(101, 0);
        priority_queue<pair<long long,int>, vector<pair<long long,int>>, greater<pair<long long,int>>> pq;
        
        for(int i=0;i<n;i++)
        {
            pq.push({meetings[0][0], i});
        }
        for(int i=0;i<meetings.size();i++)
        {
            while(pq.top().first < meetings[i][0])
            {
                pq.push({meetings[i][0], pq.top().second});
                pq.pop();
            }

            pair<long long,int> curr = pq.top();
            pq.pop();
            long long time = curr.first;
            int room = curr.second;
            pq.push({time + (meetings[i][1] - meetings[i][0]), room});
            occupancy[room]++;
        }
        
        return max_element(occupancy.begin(), occupancy.end()) - occupancy.begin();
    }
    // int mostBooked(int n, vector<vector<int>>& meets) {
    //     int cnt[101] = {};
    //     sort(begin(meets), end(meets));
    //     priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
    //     for (int i = 0; i < n; ++i)
    //         pq.push({meets[0][0], i});
    //     for (auto &m : meets) {
    //         while (pq.top().first < m[0]) {
    //             pq.push({m[0], pq.top().second});
    //             pq.pop();
    //         }
    //         auto [start, room] = pq.top(); pq.pop();
    //         pq.push({start + m[1] - m[0], room});
    //         ++cnt[room];
    //     }
    //     return max_element(begin(cnt), end(cnt)) - begin(cnt);
    // }
};