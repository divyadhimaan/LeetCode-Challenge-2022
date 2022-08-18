class Solution {
public:
    int minSetSize(vector<int>& arr) {
        int n = arr.size();
        unordered_map<int,int> mp;
        
        for(int i=0;i<arr.size();i++)
        {
            mp[arr[i]]++;
        }
        vector<int> v;
        for(auto x:mp)
            v.push_back(x.second);
        
        sort(v.begin(),v.end());
        
        int new_size = arr.size(), half = n/2, ans=0;
        for(int i=v.size()-1;i>=0;i--)
        {
            if(half < new_size)
            {
                new_size -= v[i];
                ans += 1;
                
            }else
                break;
        }
        return ans;
    }
};