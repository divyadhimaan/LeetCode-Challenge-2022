class Solution {
public:
    int furthestBuilding(vector<int>& h, int bricks, int ladders) {
        
        int n = h.size();
        priority_queue<int> pq;
        int i;
        for(i=1;i<n;i++){
            
            int diff = h[i]-h[i-1];
            
            if(diff<=0){
                continue;
            }
            
            bricks -= diff;
            pq.push(diff);
            
            if(bricks<0){
                bricks += pq.top();
                pq.pop();
                ladders--;
            }
            
            if(ladders<0){
                break;
            }
            
        }
        return i-1;
        
    }
};