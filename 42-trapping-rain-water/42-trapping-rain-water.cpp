class Solution {
public:
    int trap(vector<int>& height) {
        int lo=0,hi=height.size()-1;
        
        int leftMax=INT_MIN, rightMax=INT_MIN, ans=0;
        while(lo<hi)
        {
            leftMax = max(leftMax, height[lo]);
            rightMax = max(rightMax, height[hi]);
            
            if(leftMax<rightMax)
            {
                ans += leftMax - height[lo++];
            }else{
                ans += rightMax - height[hi--];
            }
            
            // if(height[lo]<height[hi])
            // {
            //     if(height[lo]>leftMax)
            //     {
            //         leftMax = height[lo];
            //     }else{
            //         ans+= leftMax - height[lo];
            //     }
            //     lo++;
            // }else
            // {
            //     if(height[hi]>rightMax)
            //     {
            //         rightMax = height[hi];
            //     }else{
            //         ans+= rightMax - height[hi];
            //     }
            //     hi--;
            // }
        }
        return ans;
    }
};