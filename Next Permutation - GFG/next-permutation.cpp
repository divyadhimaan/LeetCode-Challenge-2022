// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    vector<int> nextPermutation(int N, vector<int> arr){
        int i = N - 1;
        while(i > 0 && arr[i] <= arr[i - 1]){
            i--;
        }
        reverse(arr.begin() + i, arr.end());
        int l = i - 1, r = i;
        while(l >= 0 && r < N){
            if(arr[r] > arr[l]){
                swap(arr[l], arr[r]);
                break;
            }
            r++;
        }
        
        return arr;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        vector<int> arr(N);
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        vector<int> ans = ob.nextPermutation(N, arr);
        for(int u: ans)
            cout<<u<<" ";
        cout<<"\n";
    }
    return 0;
}  // } Driver Code Ends