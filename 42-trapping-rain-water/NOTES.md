BRUTE FORCE APPROACH
TC-> O(n^2)
SC-> O(1)
​
```
class Solution {
public:
int trap(vector<int>& height) {
int ans=0;
for(int i=0;i<height.size();i++)
{
int leftMax=0, rightMax=0;
for(int j=i;j>=0;j--)
{
leftMax = max(leftMax, height[j]);
}
for(int j=i;j<height.size();j++)
{
rightMax = max(rightMax, height[j]);
}
ans += min(leftMax, rightMax) - height[i];
}
return ans;
}
};
```
​
DP APPROACH
TC-> O(n)
SC-> O(n)
3 traversals required
​
​
​
**TWO POINTER APPROACH**
TC- >O(n)
SC -> O(n)
```
class Solution {
public:
int trap(vector<int>& height) {
int leftMax=0, rightMax=0;
int ans=0;
int left = 0, right = height.size()-1;