class Solution {
public:
    int calculate(string s) {
        int sum=0; 
        int sign=1;
        stack<int> st;
        for(int i=0;i<s.size();i++){
            
            if(isdigit(s[i]))
            {
                int val=0;
                while(i<s.size()&&isdigit(s[i]))
                {
                    val=val*10+(s[i]-'0');
                    i++;
                }
                i--;
                val=val*sign;
                sign=1;
                sum+=val;
            }
            
            else if(s[i]=='('){
                st.push(sum);
                st.push(sign);
                sum=0;
                sign=+1;
            }
            
            else if(s[i]==')'){
                sum*=st.top();
                st.pop();
                sum+=st.top();
                st.pop();
            }
            
            else if(s[i]=='-'){
                sign*=-1;
            }
        }
        return sum;
    }
};