class Solution {
public:
    int djikstra(vector<vector<int>>& times, int n, int k) {
        // create graph, 0th node is dummy
        // node: <dst, time>
        vector<vector<pair<int, int> > > g(n+1);
            
        for(auto edge: times) 
            g[edge[0]].emplace_back(make_pair(edge[1], edge[2]));
        
        // delay[i] = min time to reach kth node
        vector<int> delay(n+1, INT_MAX);
        
        auto comp = [&](const array<int, 2>& a, const array<int, 2>& b) { return a[1] >= b[1]; };    
        // <node, time>
        priority_queue<array<int, 2>, vector<array<int, 2>>, decltype(comp)> min_heap(comp);
        min_heap.push({k, 0});
        // starting dist will be 0
        delay[k] = 0;
        
        while(!min_heap.empty()) {
            auto [curr, curr_time] = min_heap.top();
            min_heap.pop();
            
            if(delay[curr] > curr_time)
                continue;
            
            for(auto [dst, t]: g[curr]) {
                if(delay[dst] > delay[curr] + t) {
                    delay[dst] = delay[curr] + t;
                    min_heap.push({dst, delay[curr] + t});
                }
            }
        }
        
        int max_delay = *max_element(delay.begin() + 1, delay.end());
        return max_delay == INT_MAX ? -1 : max_delay;
    }
    
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        return djikstra(times, n, k);
    }
};