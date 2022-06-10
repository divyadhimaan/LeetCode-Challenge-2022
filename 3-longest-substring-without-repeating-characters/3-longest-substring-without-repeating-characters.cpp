class Solution {
public:
    
    int max(int x, int y)
    {
        if(x> y)
            return x;
        return y;
    }
    
    int lengthOfLongestSubstring(string s) {
        if(s.length() ==0)
            return 0;
        
        int start=0, end=0, maxx=INT_MIN;
        unordered_map<int,int> mp;
        for(int i=start; i<s.length();i++)
        {
            int j=i;
            while(j<s.length() && mp[s[j]] < 1)
            {
                mp[s[j]] += 1;
                j++;
            }
            
            maxx = max(mp.size(), maxx);
            mp.clear();
        }
        
        return maxx;
    }
};