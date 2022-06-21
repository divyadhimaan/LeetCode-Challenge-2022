Approach 1: Using extra space
​
```
class Solution {
public:
void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
vector<int> nums3;
if(m==0)
{
nums1 = nums2;
return;
}
if(n==0)
return;
​
int i=0, j=0;
while(i<m && j<n)
{
if(nums1[i] <= nums2[j])
nums3.push_back(nums1[i++]);
else
nums3.push_back(nums2[j++]);
}
while(i<m)
{
nums3.push_back(nums1[i++]);
}
while(j<n){
nums3.push_back(nums2[j++]);
}
nums1 = nums3;
}
};
```