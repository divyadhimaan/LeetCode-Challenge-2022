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