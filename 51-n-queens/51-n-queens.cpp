class Solution {
public:
    
    bool isSafe(vector<string> &board, int row, int col, int n)
    {
        for(int i=0;i<n;i++)
        {
            if(board[row][i]=='Q')
                return false;
        }
        
        for(int i=row, j=col;i>=0 && j>=0;i--, j--)
        {
            if(board[i][j] == 'Q')
                return false;
        }
        
        for(int i=row, j=col;i<n && j>=0;i++, j--)
        {
            if(board[i][j] == 'Q')
                return false;
        }
        return true;
    }
    
    void solve(vector<string> &board, vector<vector<string>> &ans, int col, int n)
    {
        if(col == n)
        {
            ans.push_back(board);
            return;
        }
        
        for(int q = 0; q<n; q++)
        {
            if(isSafe(board, q, col, n))
            {
                board[q][col] = 'Q';
                solve(board, ans, col + 1, n);
                board[q][col] = '.';
            }
           
        }
    }
    
    vector<vector<string>> solveNQueens(int n) {
        vector<string> board(n);
        vector<vector<string>> ans;
        
        string s(n, '.');
        
        for(int i=0;i<n;i++)
        {
            board[i] = s;
        }
        
        solve(board, ans, 0, n);
        
        return ans;
    }
};