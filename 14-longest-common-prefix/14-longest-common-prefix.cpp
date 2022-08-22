class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n = strs.size();
        
        sort(strs.begin(), strs.end());
        
        string start = strs[0];
        string end = strs[n-1];
        
        string res = "";
        for(int i=0;i<end.size();i++)
        {
            if(start[i] == end[i])
                res += start[i];
            else
                break;
        }
        return res;
    }
};