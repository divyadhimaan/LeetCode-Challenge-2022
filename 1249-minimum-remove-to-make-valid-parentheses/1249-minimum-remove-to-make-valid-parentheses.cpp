class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack<int> stk;
        
        for(int i=0;i<s.length();i++)
        {
            if(s[i] == '(')
                stk.push(i);
            if(s[i]==')')
            {
                if(stk.empty())
                    s[i] = '-';
                else
                    stk.pop();      
            }
        }
        
        while(!stk.empty())
        {
            int i = stk.top();
            s[i] = '-';
            stk.pop();
        }
        
        string result="";
        for(int i=0;i<s.length();i++)
        {
            if(s[i]!='-')
            {
                result.push_back(s[i]);
            }
        }
        
        return result;
    }
};