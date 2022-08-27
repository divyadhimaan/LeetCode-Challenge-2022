**Recursive**
​
```
class Solution {
public:
int mod = 1e9 + 7;
int solveCost(vector<int> &cuts, int i, int j)
{
if(i>j)
return 0;
int miniCost = INT_MAX;
for(int idx = i; idx<=j; idx++)
{
int cost = (cuts[j+1] - cuts[i-1]) + solveCost(cuts, i, idx-1) + solveCost(cuts, idx+1, j);
miniCost = min(miniCost, cost);
}
return miniCost;
}
int minCost(int n, vector<int>& cuts) {
cuts.push_back(n);
cuts.insert(cuts.begin(), 0);
sort(cuts.begin(), cuts.end());
return solveCost(cuts, 1, cuts.size()-2);
}
};
```
​
TC -> exponential
​