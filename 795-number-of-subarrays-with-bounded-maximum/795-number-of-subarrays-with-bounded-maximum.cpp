class Solution {
public:
    int numSubarrayBoundedMax(vector<int>& nums, int left, int right) {
        int count=0;
        int st=0, ei=0, pcount=0;
        for(int i=0;i<nums.size();i++){
             if(nums[i]>=left && nums[i]<=right){
                 pcount=i-st+1;
                 count+=pcount;
             } else if(nums[i]<left){
                  count+=pcount;
             } else {
                 st=i+1;
                 pcount=0;
             }
        }
        return count;
    }
};