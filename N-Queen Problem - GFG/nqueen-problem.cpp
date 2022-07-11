// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:

    bool isSafe(vector<vector<int>> &board, int row, int col, int n)
    {
        for(int i=0;i<col;i++)
        {
            if(board[row][i])
                return false;
        }
        
        for(int i=row, j=col; i>=0 && j>=0; i--, j--)
        {
            if(board[i][j])
                return false;
        }
        
        for(int i=row, j=col; i<n && j>=0; i++, j--)
        {
            if(board[i][j])
                return false;
        }
        return true;
    }

    bool solve(vector<vector<int>> &board, vector<vector<int>> &ans, int col, int n)
    {
        if(col == n)
        {
            vector<int> res;
            for(int i=0;i<n;i++)
            {
                for(int j=0;j<n;j++)
                {
                    if(board[i][j]==1)
                        res.push_back(j+1);
                }
            }
            ans.push_back(res);
            return true;
        }
            
        bool res = false;
        for(int i=0;i<n;i++)
        {
            if(isSafe(board, i, col, n))
            {
                board[i][col] = 1;
                res = solve(board, ans, col+1, n) || res;
                board[i][col] = 0;
            }
        }
        return res;
    }

    vector<vector<int>> nQueen(int n) {
        vector<vector<int>> board(n, vector<int>(n,0));
        vector<vector<int>> ans;
        
        if(solve(board,ans, 0, n))
        {
            sort(ans.begin(), ans.end());
            return ans;
        }
        return {};
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        
        Solution ob;
        vector<vector<int>> ans = ob.nQueen(n);
        if(ans.size() == 0)
            cout<<-1<<"\n";
        else {
            for(int i = 0;i < ans.size();i++){
                cout<<"[";
                for(int u: ans[i])
                    cout<<u<<" ";
                cout<<"] ";
            }
            cout<<endl;
        }
    }
    return 0;
}  // } Driver Code Ends