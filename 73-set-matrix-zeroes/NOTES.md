**Approach 1: (Set) Additional Memory**
O(m*n)
O(
```
class Solution {
public:
void setZeroes(vector<vector<int>>& matrix) {
set<int> rows;
set<int> cols;
for(int i=0;i<matrix.size();i++)
{
for(int j=0;j<matrix[0].size();j++)
{
if(matrix[i][j]==0)
{
rows.insert(i);
cols.insert(j);
}
}
}
for(int i=0; i<matrix.size(); i++)
{
for(int j=0; j<matrix[0].size(); j++)
{
if(rows.find(i)!=rows.end() || cols.find(j)!=cols.end())
matrix[i][j] = 0;
}
}
}
};
```
​
**Approach 2: (O(1) Space, efficient Solution**
TC -> O(m*n)
SC -> O(1)
​
​
​