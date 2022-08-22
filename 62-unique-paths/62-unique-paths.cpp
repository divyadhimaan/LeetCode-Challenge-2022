class Solution {
public:
    int uniquePaths(int m, int n) {
        // vector<vector<int>> dp(m, vector<int>(n,0));
        vector<int> prev(n,0);

        vector<int> curr(n,0);
        curr[0] = 1;
        for(int i=0;i<m;i++)
        {
            
            for(int j=0;j<n;j++)
            {
                if(i==0 && j==0)
                    continue;
                
                if(i-1 >=0)
                    curr[j] += prev[j];
                if(j-1 >=0)
                    curr[j] += curr[j-1];
            }
            prev = curr;
            curr = vector<int>(n,0);
        }
        return prev[n-1];
    }
};