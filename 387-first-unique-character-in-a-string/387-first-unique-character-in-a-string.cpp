class Solution {
public:
    int firstUniqChar(string s) {
        int idx =-1;
        vector<int> v(26,0);
        
        for(int i=0; i<s.length();i++)
        {
            v[s[i]-'a']++;
        }
        
        for(int i=0; i<s.length();i++)
        {
            if(v[s[i] - 'a'] == 1)
            {
                idx = i;
                break;
            }
        }
        return idx;
    }
};