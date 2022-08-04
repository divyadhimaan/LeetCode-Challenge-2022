class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows==1)
            return s;
        string result="";
        vector<string> temp(numRows);
        int i=-1,n=0;
        bool flag=false;
        while(n<s.size())
        {
            if(flag==false)
                ++i;
            else 
                --i;
            temp[i]+=s[n];
            if(i==numRows-1)
                flag=true;
            else if(i==0)
                flag=false;
            ++n;
        }
        for(int i=0;i<numRows;++i)
            result+=temp[i];
        
        return result;
    }
};