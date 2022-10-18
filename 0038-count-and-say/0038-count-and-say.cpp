class Solution {
public:
    string countAndSay(int n) {
        string s = "1";
	    while(--n)
	    {
	        string ns;
	        for(int i=0;i<s.length();i++)
	        {
	            int count=1;
	            while(i+1<s.length() && s[i]==s[i+1])
	            {
	                ++count;
	                ++i;
	            }
	            ns += to_string(count) + s[i];
	        }
	        s = ns;
	    }
	    return s;
    }
};