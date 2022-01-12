class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> mp;
        
        mp.insert(make_pair('I', 1));
        mp.insert(make_pair('V', 5));
        mp.insert(make_pair('X', 10));
        mp.insert(make_pair('L', 50));
        mp.insert(make_pair('C', 100));
        mp.insert(make_pair('D', 500));
        mp.insert(make_pair('M', 1000));
        
        
        int sm=mp[s[0]];
        for(int i=1;i<s.size();i++)
            if(mp[s[i]]>mp[s[i-1]]) 
                sm+=(mp[s[i]]-2*mp[s[i-1]]);
            else 
                sm+=mp[s[i]];
        
        return sm;
    }
};