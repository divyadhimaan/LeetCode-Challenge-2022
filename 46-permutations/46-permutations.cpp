class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        rec(nums, 0, res);
        return res;
    }
    
    void rec(vector<int>& nums, int pos, vector<vector<int>> &res)
    {
        if(pos >= nums.size())
        {
            res.push_back(nums);
            return;
        }
        
        for(int i=pos;i<nums.size();i++)
        {
            swap(nums[pos], nums[i]);
            rec(nums, pos+1, res);
            swap(nums[pos], nums[i]);
        }
    }
};