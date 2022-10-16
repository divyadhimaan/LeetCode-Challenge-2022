class Solution {
public:
    bool isSubsequence(string s, string t) {
        int k=0;
        for(int i=0;i<t.length();i++)
        {
            if(t[i] == s[k])
                k++;
        }
        
        if(k==s.length())
            return true;
        
        return false;
    }
};