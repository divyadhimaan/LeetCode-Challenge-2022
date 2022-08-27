class Solution {
public:
    
    int solve(vector<int> &cuts, int index, int size, vector<vector<int>> &memo)
    {
        if(index>size)
            return 0;
        
        if(memo[index][size] != -1)
            return memo[index][size];
        
        int ans = INT_MAX;
        for(int i=index;i<=size;i++)
        {
            int currCost = cuts[size+1] - cuts[index-1];
            int cost = currCost + solve(cuts, index, i-1, memo) + solve(cuts, i+1, size, memo);
            ans = min(ans, cost);
        }
        return memo[index][size] = ans;
    }
    int minCost(int n, vector<int>& cuts) {
        int c = cuts.size();
        cuts.push_back(n);
        cuts.insert(cuts.begin(), 0);
        sort(cuts.begin(), cuts.end());
        
        vector<vector<int>> memo(c+2, vector<int> (c+2, -1));
        return solve(cuts, 1, cuts.size()-2, memo);
    }
};
//  i
//  s i       e
//  0 1 3 4 5 7