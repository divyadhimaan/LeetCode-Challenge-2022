**Brute Force**
Iterate over the array, select a number and iterate over the array again to count its occurences.
When a number appeared more than any other number, that is majority element.
We know that a majority always exists.
```
class Solution {
public:
int majorityElement(vector<int>& nums) {
int n = nums.size();
int max = n/2;
for(int i=0;i<n;i++)
{
int count=0;
for(int j=0;j<n;j++)
{
if(nums[j] == nums[i])
count += 1;
}
if(count> max)
return nums[i];
}
return -1;
}
};
```
But this exceeds the time limit.
**Time Complexity**: O(n^2)
​
**Using HashMap**
​
​