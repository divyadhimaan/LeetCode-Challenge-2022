class Solution {
public:
    
    // bool isDigit(char ch)
    // {
    //     if(ch >=0 && ch<=9)
    //         return true;
    //     else
    //         return false;
    // }
    
    int prec(char ch)
    {
        if(ch == '+' || ch == '-')
            return 1;
        if(ch == '*' || ch == '/')
            return 2;
        return -1;
    }
    
    int cal(int num1, int num2, char op)
    {
        switch(op){
            case '+':
                return num2 + num1;
            case '-':
                return num2 - num1;
            case '*':
                return num2 * num1;
            case '/':
                return num2 / num1;
            default:
                return -1;
        }
    }
    
    int calculate(string s) {
        stack<int> nums;
        stack<char> ops;
        
        for(int i=0;i<s.size();i++)
        {
            // char ch = s[i];
            
            if(s[i] == ' ')
                continue;
            
            else if(isdigit(s[i])){
                cout<<s[i]<<" ";
                long num = 0;
                
                while(i < s.size() && isdigit(s[i]))
                {
                    num = num*10 + s[i]-'0';
                    i++;
                }
                nums.push(num);
                i--;
            }
            
            else {
                cout<<1<<" ";
                while(!ops.empty() && prec(ops.top()) >= prec(s[i]))
                {
                    int num1 = nums.top();
                    nums.pop();
                    int num2 = nums.top();
                    nums.pop();
                    
                    int out = cal(num1, num2, ops.top());
                    cout<<out<<" ";
                    nums.push(out);
                    ops.pop();
                }
                ops.push(s[i]);
                
                
            }
        }
        
        while(!ops.empty())
        {
            int num1 = nums.top();
            nums.pop();
            int num2 = nums.top();
            nums.pop();

            int out = cal(num1, num2, ops.top());

            nums.push(out);
            ops.pop();
        }
        
        return nums.top();
        
    }
};