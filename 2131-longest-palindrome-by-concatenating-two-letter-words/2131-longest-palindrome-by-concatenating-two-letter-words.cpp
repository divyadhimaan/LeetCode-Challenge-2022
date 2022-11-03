class Solution {
public:
    
    int longestPalindrome(vector<string>& words) {
        
        int count = 0;
        unordered_map<string,int> mp;
        string temp;
        for(string word: words)
        {
            temp = word;
            reverse(temp.begin(), temp.end());
            
            if(mp[temp]>0)
            {
                count+=4;
                mp[temp]--;
            }else{
                mp[word]++;
            }
                
        }
        
        for(string word: words)
        {
            if(word[0] == word[1] && mp[word] > 0)
            {
                count += 2;
                break;
            }
        }
        return count;
        
    }
};