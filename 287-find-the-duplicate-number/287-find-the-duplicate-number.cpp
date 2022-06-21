class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        set<int> visited;
        
        for(int i=0;i<nums.size();i++)
        {
            if(visited.find(nums[i]) != visited.end())
                return nums[i];
            else
                visited.insert(nums[i]);
        }
        return 0;
    }
};