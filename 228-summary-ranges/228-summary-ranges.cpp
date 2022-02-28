# define ll long long 
class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> result;
        
        if(nums.size()==0)
            return result;
        
        bool has_started = false;
        string ans="";
        int i=1;
        for(i=1;i<nums.size();++i)
        {
            // int diff = nums[i] - nums[i-1];
            if(!has_started)
            {
                if(nums[i] == nums[i-1] + 1)
                {
                    ans += to_string(nums[i-1]); 
                    has_started = true;
                } 
                else if(nums[i] > nums[i-1] + 1)
                {
                    result.push_back(to_string(nums[i-1]));
                }
            } else{
                if(nums[i] > nums[i-1] + 1){
                    ans += "->" + to_string(nums[i-1]);
                    has_started = false;
                    result.push_back(ans);
                    ans="";
                }
            }
        }
        if(has_started) {
            ans += "->" + to_string(nums[i-1]);
            has_started = false;
            result.push_back(ans);
        } else
            result.push_back(to_string(nums[i-1]));
            
        return result;
        
    }
};