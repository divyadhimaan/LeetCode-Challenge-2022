class Solution {
public:
    
    int ceilIdx(vector<int> &tail, int l, int h, int x)
    {
        while(l<h)
        {
            int m = l + (h-l)/2;
            
            if(tail[m] >= x)
                h = m;
            else
                l = m+1;
        }
        return h;
    }
    
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        
        vector<int> tail(n);
        
        int len = 1;
        tail[0] = nums[0];
        
        for(int i=1;i<n;i++)
        {
            if(nums[i]>tail[len-1])
            {
                tail[len++] = nums[i];
            }else {
                int idx = ceilIdx(tail, 0, len-1, nums[i]);
                // cout<<idx<<endl;
                tail[idx] = nums[i];
            }
        }
        // for(int i=0;i<tail.size();i++)
        //     cout<<tail[i];
        
        return len;
    }
};