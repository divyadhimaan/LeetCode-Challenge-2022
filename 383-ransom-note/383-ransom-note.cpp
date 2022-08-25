class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        vector<int> hash(26,0);
        
        for(int i=0;i<magazine.length();i++)
        {
            hash[magazine[i]-'a']++;
        }
        
        for(int i=0;i<ransomNote.length();i++)
        {
            if(hash[ransomNote[i]-'a'] == 0)
                return false;
            else
                hash[ransomNote[i]-'a']--;
        }
        
        return true;
    }
};