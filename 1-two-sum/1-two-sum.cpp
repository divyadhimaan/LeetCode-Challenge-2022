class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> numsHash;
        
        for (int i = 0; i < nums.size(); ++i) {
            if (numsHash.find(target - nums[i]) == numsHash.end())
                numsHash[nums[i]] = i; 
            else
                return {numsHash[target - nums[i]], i};
        }
        
        return {};
    }
};