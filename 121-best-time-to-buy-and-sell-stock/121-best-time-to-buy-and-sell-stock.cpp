class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int currmin = prices[0];
        int ans = 0;
        for(int i=1;i<prices.size();i++){
            ans = max(ans,prices[i]-currmin);
            currmin = min(currmin,prices[i]);
        }
        return ans;
    }
};