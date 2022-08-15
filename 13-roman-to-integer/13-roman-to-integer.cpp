class Solution {
public:
    int romanToInt(string s) {
        if(s.length()==0)
            return 0;
        
        unordered_map<char, int> table = {
            {'I', 1},
            {'V', 5},
            {'X', 10},
            {'L', 50},
            {'C', 100},
            {'D', 500},
            {'M', 1000}
        };
        
        int res =0;
        
        for(int i=0; i<s.length()-1;i++)
        {
            if(table[s[i]] < table[s[i+1]])
                res -= table[s[i]];
            else
                res += table[s[i]];
        }
        
        
        res += table[s.back()];
        
        return res;
    }
};