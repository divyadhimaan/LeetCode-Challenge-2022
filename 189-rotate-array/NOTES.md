Method 0:
```
void rotate(vector<int>& nums, int k) {
for(int i=0;i<k;i++)
{
int temp = nums[nums.size()-1];
int j = nums.size()-2;
for(;j>=0;j--)
{
nums[j+1] = nums[j];
}
nums[j+1] = temp;
}
}
```
​
**Method 1 (Easiest Approach)**
Uses additional memory
```
class Solution {
public:
void reverse(vector<int>& nums, int i, int j) {
while (i < j)
swap(nums[i++], nums[j--]);
}
void rotate(vector<int>& nums, int k) {
k = k % nums.size();
if (nums.size() <= 1) return;
reverse(nums, 0, nums.size()-1);
reverse(nums, k, nums.size()-1);
reverse(nums, 0, k-1);
}
};
```
​
Method 2: