class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        vector<int> sums(nums.size(), 0);
        sums[0] = nums[0];
        for(int i=1;i<nums.size();i++)
        {
            sums[i] = sums[i-1] + nums[i];
        }
        return sums;
    }
};