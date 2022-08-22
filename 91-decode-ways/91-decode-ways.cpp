class Solution {
public:
    // int memo[]
    int ways(string s, int i, vector<int> &memo)
    {
        if(i==s.length())
            return 1;
        
        if(memo[i] != -1)
            return memo[i];
        
        int count=0;
        if(s[i] != '0')
            count += ways(s,i+1,memo);
        
        if(i+1 < s.length() && (s[i] == '1' || (s[i] == '2' && s[i+1] <='6')))
            count += ways(s,i+2,memo);
        
        return memo[i] = count;
    }
    
    int numDecodings(string s) {
        vector<int> memo(s.length(), -1);
        return ways(s,0, memo);
    }
};