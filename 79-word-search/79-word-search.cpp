class Solution {
public:
    
    vector<int> dx = {1,-1,0,0};
    vector<int> dy = {0,0,-1,1};
    
    bool DFS(vector<vector<char>>& board, int i, int j,string word)
    {
        if(!word.length())
            return true;
        
        if(i<0 || j<0 || i>=board.size() || j>=board[0].size() || board[i][j] !=word[0])
            return false;
        
        char c=board[i][j];
        board[i][j] = '*';
        
        string s = word.substr(1);
        
        for(int k=0;k<4;k++)
        {
            int ni = i+dx[k];
            int nj = j+dy[k];
            
            
            if(DFS(board, ni, nj, s))
                return true;
        }
        board[i][j] = c;
        return false;
    }
    
    bool exist(vector<vector<char>>& board, string word) {
        if(word=="")
            return false;
        
        for(int i=0;i<board.size();i++)
        {
            for(int j=0;j<board[0].size();j++)
            {
                if(board[i][j] == word[0])
                    if(DFS(board, i, j, word))
                        return true;
            }
        }
        return false;
    }
};