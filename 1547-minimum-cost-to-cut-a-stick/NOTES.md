```
class Solution {
public:
int mod = 1e9 + 7;
int solveCost(vector<int> &cuts, int i, int j, vector<vector<int>> &memo)
{
if(i>j)
return 0;
if(memo[i][j] != -1)
return memo[i][j];
int miniCost = INT_MAX;
for(int idx = i; idx<=j; idx++)
{
int cost = (cuts[j+1] - cuts[i-1]) + solveCost(cuts, i, idx-1, memo) + solveCost(cuts, idx+1, j, memo);
miniCost = min(miniCost, cost);
}
return memo[i][j] = miniCost;
}
int minCost(int n, vector<int>& cuts) {
cuts.push_back(n);
cuts.insert(cuts.begin(), 0);
sort(cuts.begin(), cuts.end());
vector<vector<int>> memo(cuts.size(), vector<int>(cuts.size(), -1));
return solveCost(cuts, 1, cuts.size()-2, memo);
}
};
```
M->size of cuts array
TC -> O(M*M*M)
SC -> O(M*M) +Stack SPace
​
​