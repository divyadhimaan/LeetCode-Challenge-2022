**Method - I **
Inefficient but Accepted
(Simple Traversal of array)
Time Complexity: log(n)
```
class Solution {
public:
vector<int> searchRange(vector<int>& nums, int target) {
vector<int> ans;
int last=-1;
bool has_found = false;
for(int i=0;i<nums.size();i++)
{
if(nums[i] == target && has_found == false)
{
has_found = true;
ans.push_back(i);
last = i;
}
else if(nums[i] == target)
{
last = i;
}
}
if(last != -1)
ans.push_back(last);
else
{
ans.push_back(-1);
ans.push_back(-1);
​
}
return ans;
}
};
```
​
**Method - II**
(Binary Search)
Time Complexity: O(log n)
​
```
​
```