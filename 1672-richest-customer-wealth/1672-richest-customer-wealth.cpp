class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int n = accounts.size();
        int sum = 0,max = INT_MIN;
        for(int i=0;i<n;i++)
        {
            sum =0;
            for(int j=0;j<accounts[i].size();j++)
            {
                sum += accounts[i][j];
            }
            if(sum> max)
                max = sum;
        }
        
        return max;
    }
};