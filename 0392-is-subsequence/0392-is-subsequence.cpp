class Solution {
public:
    bool isSubs(string& s, string& t, int m, int n,  vector<vector<int>> &memo)
    {
        if(m == 0)
            return true;
        if(n == 0)
            return false;
        
        if(memo[m][n] != -1)
            return memo[m][n];
        
        if (s[m - 1] == t[n - 1])
            return memo[m][n] = isSubs(s, t, m - 1, n - 1, memo);
 
        return memo[m][n] = isSubs(s, t, m, n - 1, memo);
    }
    
    
    bool isSubsequence(string s, string t) {
        
        vector<vector<int>> memo(s.length()+1, vector<int>(t.length()+1, -1));
       if( isSubs(s,t,s.length(),t.length(),memo))
           return true;
        
        return false;
        
    }
};