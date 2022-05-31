class Solution {
public:
    bool hasAllCodes(string s, int k) {
        //If string doesnt contain enough characters to traverse through we return false
        if(s.size()<k) return false;
        
        //Creation of set to store different possible combinations
        unordered_set<string> st;
        
        //Storing all the substrings of size K in our set
        for(int i=0;i<s.size()-k+1;i++)
            st.insert(s.substr(i, k));
        
        
        //If set's size is equal to 2 power k,
        //then we have all the possible substrings else we return false
        return st.size()==pow(2, k);
    }
};