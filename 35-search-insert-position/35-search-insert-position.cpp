class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int index=0;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i] == target)
                index = i;
            
            else{
                if(i == nums.size()-1 && nums[i]<target)
                {
                    index = i+1;
                }
                else if(nums[i] < target && nums[i+1] > target)
                {
                    index = i+1;
                }
            }
        }
        return index;
        
        
        // int s = 0 , e = nums.size()-1;
        // while(s <= e){
        //     int mid = s + (e-s)/2;
        //     if(nums[mid] == target)
        //         return mid;
        //     else if(nums[mid] < target)
        //         s = mid + 1;
        //     else if(nums[mid] > target)
        //         e = mid - 1;
        // }
        // return s;
    }
};