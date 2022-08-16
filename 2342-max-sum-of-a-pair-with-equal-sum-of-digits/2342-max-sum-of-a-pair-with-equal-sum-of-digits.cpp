class Solution {
public:
    
    long long findSum(int n)
    {
        if(n/10 == 0)
            return n;
        
        long long sum=0;
        while(n)
        {
            sum += n%10;
            n /= 10;
        }
        return sum;
    }
    
    int maximumSum(vector<int>& nums) {
        unordered_map<long long, vector<int>> mp;
        
        for(int i=0;i<nums.size();i++)
        {
            int sum = findSum(nums[i]);
            
            mp[sum].push_back(nums[i]);
        }
        // for(auto x: mp)
        // {
        //     vector<int> v = x.second;
        //     cout<<x.first<<" - ";
        //     for(int i=0;i<v.size();i++)
        //         cout<<v[i]<<" ";
        //     cout<<endl;
        // }
        
        int maxx = INT_MIN;
        
        for(auto x: mp)
        {
            vector v = x.second;
            sort(v.begin(), v.end(), greater<int>());
            
            int sum = 0;
            if(v.size()>1)
            {
                sum += v[0] + v[1];
                maxx = max(maxx, sum);
            }
            
        }
        if(maxx == INT_MIN)
            return -1;
        return maxx;
        
    }
};