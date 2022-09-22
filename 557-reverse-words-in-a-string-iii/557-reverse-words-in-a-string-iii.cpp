class Solution {
public:
    string reverseWords(string s) {
        
        int start=0, end=0;
        for(int i=0;i<s.length();i++)
        {
            if(s[i]==' ')
            {
                reverse(s.begin()+start, s.begin()+end);
                start=i+1;
                end=start;
            }
            else
            {
                end++;
            }
        }
        reverse(s.begin()+start, s.begin()+end);
        return s;
    }
};