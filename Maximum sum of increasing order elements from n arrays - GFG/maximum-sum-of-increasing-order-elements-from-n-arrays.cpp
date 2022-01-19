// { Driver Code Starts
// CPP program to find maximum sum
// by selecting a element from n arrays
#include<bits/stdc++.h>

using namespace std;

// To calculate maximum sum by
// selecting element from each array
int maximumSum( int n,int m, vector<vector<int>> &a);



// Driver program to test maximumSum
int main() {
    int t,n,m;
    cin>>t;
    while(t--)
    {
        cin>>n>>m;
        vector<vector<int>> arr(n, vector<int>(m,0));
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
            cin>>arr[i][j];
            
        cout << maximumSum(n,m,arr)<<endl;
    
    }
    return 0;

}
// } Driver Code Ends


int maximumSum( int n,int m, vector<vector<int>> &a) {

    for(int i=0;i<a.size();++i){
    sort(a[i].begin(),a[i].end());   
   }
   //cout<<a[0][5];
   int sum=0;
   int i=a.size()-1;
   int j=a[0].size()-1;
   int temp=a[i][j];
   sum+=temp;
   --i;
   while(i>=0 && j>=0){
       if(a[i][j]<temp){
           temp=a[i][j];
           sum+=temp;
           --i;
           j=m-1;
       }
       else{
           --j;
       }
   }
   if(i>0 || j<0){
       return 0;
   }
   return sum;
}