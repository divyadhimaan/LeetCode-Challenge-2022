class Solution {
public:
    
    int solve(int n, vector<int> &cuts, int start, int end, int index, int size, vector<vector<int>> &memo)
    {
        if(index>size)
            return 0;
        
        if(memo[index][size] != -1)
            return memo[index][size];
        int currCost = end - start;
        int ans = INT_MAX;
        for(int i=index;i<=size;i++)
        {
            int cost = currCost + solve(n, cuts, start,cuts[i], index, i-1, memo) + solve(n, cuts, cuts[i],end, i+1, size, memo);
            ans = min(ans, cost);
        }
        return memo[index][size] = ans;
    }
    int minCost(int n, vector<int>& cuts) {
        sort(cuts.begin(), cuts.end());
        vector<vector<int>> memo(cuts.size()+1, vector<int> (cuts.size()+1, -1));
        return solve(n, cuts, 0, n, 0, cuts.size()-1, memo);
    }
};
//  i
//  s i           e
//  0 1 3 4 5 7