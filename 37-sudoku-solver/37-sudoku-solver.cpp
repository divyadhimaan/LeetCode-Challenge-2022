class Solution {
public:
    
    bool isSafe(vector<vector<char>>& board, int row, int col, char num)
    {
        for(int i=0;i<9;i++)
        {
            if(board[i][col] == num)
            {
                return false;
            }
        }
        
        for(int i=0;i<9;i++)
        {
            if(board[row][i] == num)
                return false;
        }
        
        int s = sqrt(9);
        int rowStart = row - (row%s);        
        int colStart = col - (col%s);
        
        for(int r = rowStart; r < rowStart+s; r++)
        {
            for(int c = colStart; c < colStart+s; c++)
            {
                if(board[r][c] == num)
                    return false;
            }
        }
        return true;
    }
    
    bool solve(vector<vector<char>>& board, int N)
    {
        int row = -1;
        int col = -1;
        bool isEmpty = true;
        
        for(int i=0;i<N;i++)
        {
            for(int j=0;j<N;j++)
            {
                if(board[i][j] == '.')
                {
                    row = i;
                    col = j;
                    isEmpty = false;
                    break;
                }
            }
            if(!isEmpty)
                break;
        }
        
        if(isEmpty)
            return true;
        
        for(char num='1'; num <= '9'; num++)
        {
            if(isSafe(board, row, col, num))
            {
                board[row][col] = num;
                
                if(solve(board, N))
                    return true;
                
                board[row][col] = '.';
            }
        }
        return false;
    }
    
    void solveSudoku(vector<vector<char>>& board) {
        solve(board, board.size());
    }
};