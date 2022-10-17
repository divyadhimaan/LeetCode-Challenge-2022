class Solution {
public:
    bool checkIfPangram(string sentence) {
        vector<int> hash(26, 0);
        
        for(char l: sentence)
        {
            hash[l - 'a']++;
        }
        for(int i=0;i<26;i++)
        {
            if(hash[i] == 0)
                return false;
        }
        return true;
    }
};