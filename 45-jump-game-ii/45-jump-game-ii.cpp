class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        int maxR = nums[0];
        int steps = nums[0];
        int jumps=1;
        
        if(n == 1)
            return 0;
        else if(nums[0] == 0)
            return -1;
        else{
            for(int i=1;i<n;i++)
            {
                if(i == n-1)
                    return jumps;
                
                maxR = max(maxR, nums[i] + i);
                steps--;
                
                if(steps == 0)
                {
                    jumps++;
                    if(i > maxR)
                        return -1;
                    
                    steps += maxR - i;
                }
            }
        }
        
        return jumps;
    }
};