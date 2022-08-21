// class Solution {
// public:
//     bool canJump(vector<int>& nums) {
        
//         int n = nums.size();
//         vector<bool>dp(n, false);
        
//         dp[0] = true;
//         for(int i=1;i<n;i++)
//         {
//             for(int j=i-1;j>=0;j--)
//             {
//                 if(dp[j] && nums[j] + j >= i)
//                 {
//                     dp[i] = true;
//                     break;
//                 }
//             }
//         }
        
//         return dp[n-1];
//     }
// };

class Solution {
    public:
    bool canJump(vector<int>& nums) {
     
        int n=nums.size();
        int reachable=0;
        
        for(int i=0;i<n;i++){
            if(i>reachable) return false;
            reachable=max(reachable,i+nums[i]);
        }
        return true;
        
    }
};