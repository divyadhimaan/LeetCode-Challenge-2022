class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n = nums.size();
        int sum=0,leftSum=0;
        
        for(int i=0;i<n;i++)
            sum += nums[i];

        for(int i=0;i<n;i++)
        {
            if(leftSum == sum - leftSum - nums[i])
                return i;
            
            leftSum += nums[i];
        }
        return -1;
    }
};