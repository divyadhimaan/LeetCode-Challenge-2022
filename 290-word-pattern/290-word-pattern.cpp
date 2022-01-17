class Solution {
public:
    bool wordPattern(string pattern, string s) {
        int count = 0;
        for(int i=0;i<s.length();i++)
        {
            if(s[i]== ' ')
                count++;
        }
        count += 1;
        if(pattern.size() != count)
            return false;
        
        vector<string> words;
        string word = "";
        for(int i=0;i<s.length();i++)
        {
            if(s[i]== ' ')
            {
                words.push_back(word);
                word = "";
            }
                
            else
                word += s[i];
        }
        words.push_back(word);
        
        unordered_map<char,string> mp1; 
        unordered_map<string,char> mp2;
        
        for(int i=0;i<pattern.length();i++)
        {
            if(mp1.find(pattern[i]) == mp1.end() && mp2.find(words[i]) == mp2.end())
            {
                mp1[pattern[i]] = words[i];
                mp2[words[i]] = pattern[i];
            }
            else if(mp1.find(pattern[i]) != mp1.end() && mp2.find(words[i]) != mp2.end())
            {
                if(mp1[pattern[i]]!=words[i])
                    return false;
                if(mp2[words[i]]!=pattern[i])
                    return false;     
            }
            else
            {
                return false;
            }
        }
        return true;
    }
};