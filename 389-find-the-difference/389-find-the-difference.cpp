class Solution {
public:
    char findTheDifference(string s, string t) {
        if(s.length() == 0)
            return t[0];
        int sSum =0;
        for(int i=0;i<s.length();i++)
        {
            sSum+= s[i] - 'a';
        }
        int tSum =0;
        for(int i=0;i<t.length();i++)
        {
            tSum+= t[i] - 'a';
        }
        
        return (tSum - sSum) + 'a';
        // return 'a';
    }
};