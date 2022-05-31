class Solution {
public:
    bool hasAllCodes(string s, int k) {
        if(s.length()<k)
            return false;

        unordered_set<string> st;
        
        for(int i=0;i<s.size()-k+1;i++)
        {
            string ss = s.substr(i,k);
            st.insert(ss);
        }
            
        return st.size()==pow(2, k);
    }
};