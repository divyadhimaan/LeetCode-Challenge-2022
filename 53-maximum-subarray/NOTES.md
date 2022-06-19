This can be done using **Kadane's Algorithm**
O(n)
​
```
Initialize:
max_so_far = INT_MIN
max_ending_here = 0
​
Loop for each element of the array
(a) max_ending_here = max_ending_here + a[i]
(b) if(max_so_far < max_ending_here)
max_so_far = max_ending_here
(c) if(max_ending_here < 0)
max_ending_here = 0
return max_so_far
```
​
​
```
class Solution {
public:
int maxSubArray(vector<int>& nums) {
int max = 0, max_so_far = INT_MIN;
for(int i=0;i<nums.size();i++)
{
max += nums[i];
if(max > max_so_far)
max_so_far =max;
if(max < 0)
max =0;
}
return max_so_far;
}
};
```
​
​