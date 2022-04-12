class Solution
{
public:
    // Function to compare all neighbor of index (i,j)
    int countAliveNeighbor(vector<vector<int>> &board, int i, int j)
    {
        int n = board.size();
        int m = board[0].size();
        // cnt to store the total number of alive neighbor
        int cnt = 0;

        // conditions to check
        // whether neighbour index is valid
        // if it is a valid index and with value 1 or -1 we will increment the cnt
        if (i - 1 > -1 && j - 1 > -1 && (board[i - 1][j - 1] == 1 || board[i - 1][j - 1] == -1))
            cnt++;
        if (i - 1 > -1 && (board[i - 1][j] == 1 || board[i - 1][j] == -1))
            cnt++;
        if (j - 1 > -1 && (board[i][j - 1] == 1 || board[i][j - 1] == -1))
            cnt++;
        if (i + 1 < n && j + 1 < m && (board[i + 1][j + 1] == 1 || board[i + 1][j + 1] == -1))
            cnt++;
        if (i + 1 < n && (board[i + 1][j] == 1 || board[i + 1][j] == -1))
            cnt++;
        if (j + 1 < m && (board[i][j + 1] == 1 || board[i][j + 1] == -1))
            cnt++;
        if (i - 1 > -1 && j + 1 < m && (board[i - 1][j + 1] == 1 || board[i - 1][j + 1] == -1))
            cnt++;
        if (i + 1 < n && j - 1 > -1 && (board[i + 1][j - 1] == 1 || board[i + 1][j - 1] == -1))
            cnt++;

        // returning the cnt
        return cnt;
    }
    void gameOfLife(vector<vector<int>> &board)
    {
        int n = board.size();
        int m = board[0].size();
        // iterating over all the elements
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                // call countAliveNeighbor() function to return number of alive neighbor for index (i,j)
                int count = countAliveNeighbor(board, i, j);
                if (board[i][j] == 1)
                {
                    // if count < 2 or count > 3
                    // then this index will die in next state
                    // so as an indicator for that we change it's value to -1
					// Hence -1 indicates that this index is alive in present state but will die in next state
                    if (count < 2 || count > 3)
                        board[i][j] = -1;
                }
                else
                {
                    // count == 3
                    // then this index will become alive in next state
                    // so as an indicator for that we change it's value to -2
					// Hence -2 indicates that this index is dead in present state but will be alive in next state
                    if (count == 3)
                        board[i][j] = -2;
                }
            }
        }

        // in the end we update the borad to it's next state
        // if board[i][j]==-1 means dead in next state
        // board[i][j] becomes 0
        // if board[i][j]==-2 means alive in next state
        // board[i][j] becomes 1
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                if (board[i][j] == -1)
                    board[i][j] = 0;
                else if (board[i][j] == -2)
                    board[i][j] = 1;
    }
};