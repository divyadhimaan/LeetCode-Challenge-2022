// { Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function template for C++

class Solution{
    public:
    
    // bool isSafe(vector<vector<int>> &m, int n, int i, int j)
    // {
    //     return (i<n && j<n && i>=0 && j>=0 && m[i][j]==1);
    // }
    
    void findPathRec(vector<vector<int>> &m, int n, int i, int j, vector<string> &ans, string s)
    {
        if(i>=n || j>=n ||  i<0 || j<0 || m[i][j]==0)
            return;
        
        if(i==n-1 && j == n-1)
        {
            ans.push_back(s);
            return;
        }
        
        // if(isSafe(m, n, i, j) == true)
        // {
            m[i][j] = 0;
            
            findPathRec(m, n, i+1, j, ans, s + "D");
            findPathRec(m, n, i, j+1, ans, s + "R");
            findPathRec(m, n, i-1, j, ans, s + "U");
            findPathRec(m, n, i, j-1, ans, s + "L");
            
            m[i][j] = 1;
            
        // }
        return;
    }
    
    vector<string> findPath(vector<vector<int>> &m, int n) {
        vector<string> ans;

        findPathRec(m, n, 0, 0, ans, "");
        
        return ans;
        
    }
};

    


// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}  // } Driver Code Ends