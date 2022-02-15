class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans{-1,-1};
        int first=-1,last=-1;
        bool has_found = false;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i] == target && has_found == false)
            {
                has_found = true;
                first = i;
                last = i;
            }
            else if(nums[i] == target)
            {
                last = i;
            }
        }
        if(last != -1)
        {
            ans[0] = first;
            ans[1] = last;
        }
            
        
        
        return ans;
    }
};