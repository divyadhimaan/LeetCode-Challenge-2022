class Solution {
public:
    
    bool checkInclusion(string s1, string s2) {
        if(s2.size() < s1.size())
            return false;
        
        vector<int> v1(26,0);
        vector<int> v2(26,0);
        
        for(auto i: s1)
            v1[i - 'a']++;
        
        int start=0, end= 0;
        while(end < s2.size()){
            v2[s2[end] - 'a']++;
            
            if(end - start + 1 == s1.size()){
                if(v1==v2)
                    return true;
            }
            
            if(end - start + 1 < s1.size())
            {
                end++;
            }else{
                v2[s2[start] - 'a']--;
                start++;
                end++;
            }
        }
        
        return false;
    }
};

