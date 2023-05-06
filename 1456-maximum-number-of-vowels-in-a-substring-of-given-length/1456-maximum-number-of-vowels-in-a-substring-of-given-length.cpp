class Solution {
public:

    bool isVowel(char c)
    {
        if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
            return true;
        return false;
    }

    int maxVowels(string s, int k) {
        int start = 0, end = 0;

        int vowelCount = 0, maxVowelCount=0;
        while(end < s.length())
        {
            if(isVowel(s[end]))
                vowelCount++;
            
            if(end - start == k)
            {
                if(isVowel(s[start]))
                    vowelCount--;
                start++;
            }
            
            maxVowelCount = max(maxVowelCount, vowelCount);
            end++;
            
        }
        return maxVowelCount;
    }
};