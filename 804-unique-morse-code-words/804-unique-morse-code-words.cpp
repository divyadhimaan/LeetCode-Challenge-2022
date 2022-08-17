class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        vector<string> morse{".-","-...","-.-.","-..",".","..-.","--.",
                         "....","..",".---","-.-",".-..","--","-.",
                         "---",".--.","--.-",".-.","...","-","..-",
                         "...-",".--","-..-","-.--","--.."};
        
        set<string> hash;
        
        if(words.size() <= 1)
            return words.size();
        
        string res = "";
        for(int i=0;i<words.size();i++)
        {
            res="";
            for(int j=0;j<words[i].size();j++)
            {
                res += morse[words[i][j] - 'a'];
            }
            hash.insert(res);
        }
        
        return hash.size();
    }
};