// { Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
//User function Template for C++
class Solution
{
public:
    void vectorize(vector<int> &v,int a[],int N,int temp)
    {
        for(int i=1;i<N;i++)
            temp = (temp*10)+a[i];
        v.push_back(temp);    
    }
    void recurse(int a[],int N,vector<int> &v,int pos,int max)
    {
        if(pos<N)
            for(int i=max+1;i<10;i++)
                a[pos]=i,recurse(a,N,v,pos+1,i);
        else if(pos==N)
            vectorize(v,a,N,a[0]);
    }
    vector<int> increasingNumbers(int N)
    {
        vector<int> v;
        int a[N],i;
        for(i=0;i<N;i++)
            a[i]=0;
        if(N==1)
            for(i=0;i<10;i++)
                v.push_back(i);
        else
            recurse(a,N,v,0,0);
        return v;    
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin>>N;
        Solution ob;
        vector<int> ans = ob.increasingNumbers(N);
        for(auto num : ans){
            cout<< num <<" ";
        }
        cout<<endl;
        
    }
    return 0;
}  // } Driver Code Ends