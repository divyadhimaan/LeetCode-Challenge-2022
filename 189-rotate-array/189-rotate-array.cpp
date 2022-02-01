class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        if(k==0)
            return;
        if(k > n)
            k = k%n;
        
        reverse(nums.begin(),(nums.begin() + (n - k ))); //last index not included
        reverse((nums.begin() + (n - k  )), nums.end()); 
        reverse(nums.begin(), nums.end());
    }
};