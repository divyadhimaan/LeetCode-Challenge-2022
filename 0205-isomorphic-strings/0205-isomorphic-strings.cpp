class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char,char> mp1;
        unordered_map<char,char> mp2;
       
        for(int i=0;i<s.length();i++)
        {
            char c = s[i];
            char p = t[i];
            // cout<<c<<" "<<p<<endl;
            
            if(mp1.find(c) != mp1.end())
            {
                // cout<<"in map1"<<endl;
                if(mp1[c] != p)
                    return false;
            }
            else if(mp2.find(p) != mp2.end())
            {
                // cout<<"in map2"<<endl;
                if(mp2[p] != c)
                    return false;
            }
            else{
                // cout<<c<<" -> "<<p<<endl;
                // cout<<p<<" -> "<<c<<endl;
                mp1[c] = p;
                mp2[p] = c;
            }
        }
        return true;
    }
};