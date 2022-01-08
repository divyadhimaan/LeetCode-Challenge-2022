// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++

class Solution{   
public:
    string convertToWords(long n) {
        string ones[10]={"","one ","two ","three ","four ","five ","six ","seven ","eight ","nine "};
        string tens1[10]={"ten ","eleven ","twelve ","thirteen ","fourteen ","fifteen ","sixteen ","seventeen ","eighteen ","nineteen "};
        string tens2[10]={"","","twenty ","thirty ","forty ","fifty ","sixty ","seventy ","eighty ","ninety "};
        string bigger[4]={"hundred","thousand ","lakh ","crore "};
        
        int i=0;
        string ans="";
        int f=0,hundred;
        while(n>0){
            string s1="";
            int one=n%10;
            n/=10;
            int ten=n%10;
            n/=10;
            if(ten==0){
                s1=ones[one];
            }
            else{
                if(ten==1){
                    s1=tens1[one];
                }
                else{
                    s1=tens2[ten]+ones[one];
                }
            }
            if(i==0){
                hundred=n%10;
                n=n/10;
            }
            if(i==0 && hundred!=0){
                if(s1.size()>1)s1=ones[hundred]+"hundred and "+s1;
                else{
                    s1=ones[hundred]+"hundred ";
                }
                f=1;
             }
            else if(i>=1 and s1.size()>1){
                if(f==1)s1=s1+bigger[i];
                else{
                    s1=s1+bigger[i]+"and ";
                    f=1;
                }
            }
            ans=s1+ans;
            i++;
            
        }
        
        return ans;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        long n;
        cin >> n;
        Solution ob;
        auto ans = ob.convertToWords(n);
        cout << ans << "\n";
    }
    return 0;
}  // } Driver Code Ends