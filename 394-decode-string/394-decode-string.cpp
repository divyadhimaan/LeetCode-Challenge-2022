class Solution {
public:
    string decodeString(string s) {
        stack<pair<string,int>> stk;
        string res = "";
        int num = 0;
        string str = "";
        for(int i=0;i<s.length();i++)
        {

            if(isdigit(s[i]))
            {
                num = num*10 + s[i] - '0';
            }
            else if(s[i] == '['){
                stk.push({str,num});
                num=0;
                str="";
            }
            else if(s[i]==']'){
                string tmp = str;
                for(int j=1;j<stk.top().second;j++)
                {
                    tmp += str;
                }
                str=stk.top().first+tmp;
                stk.pop();
            }else{
                str += s[i];
            }
        }
        return str;
    }
};