class Solution {
public:
    bool detectCapitalUse(string word) {
        bool is_right = true;
        for(int i=1;i<word.length();i++)
        {
            if((isupper(word[1]) != isupper(word[i]))  ||  (islower(word[0]) && isupper(word[i])))
            {
                is_right = false;
            }
        }
        
        return is_right;

    }
};