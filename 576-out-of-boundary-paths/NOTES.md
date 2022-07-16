Approach 1: Recursion
TC -> O(4^n)
SC -> O(n+m)
​
```
class Solution {
public:
int solve(int m, int n, int maxMove, int i, int j)
{
if(i == m || j == n || i<0 || j<0)
return 1;
if(maxMove == 0)
return 0;
int left = solve(m, n, maxMove-1, i, j-1);
int right = solve(m, n, maxMove-1, i, j+1);
int up = solve(m, n, maxMove-1, i-1, j);
int down = solve(m, n, maxMove-1, i+1, j);
return left + right + up + down;
}
int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
return solve(m, n, maxMove, startRow, startColumn);
​
}
};
```
​
Approach 2: