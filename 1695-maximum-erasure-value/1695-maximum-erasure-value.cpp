class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
//         sliding window approach
        unordered_set<int> st;
        int curr_sum = 0, max_sum = INT_MIN;
        
        for(int i=0, j=0;j<nums.size();j++)
        {
            while(st.find(nums[j]) != st.end())
            {
                curr_sum = curr_sum - nums[i];
                st.erase(nums[i]);
                i++;
            }
            
            curr_sum += nums[j];
            st.insert(nums[j]);
            
            max_sum = max(max_sum, curr_sum);
            
        }
        
        return max_sum;
    }
};