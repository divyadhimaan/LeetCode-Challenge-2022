class TrieNode{
    public:
        bool isWord;
        string word;
        TrieNode* child[26];
    
    
        TrieNode()
        {
            isWord = false;
            for(int i=0;i<26;i++)
                child[i] = NULL;
        }
};

class Solution {
public:
    TrieNode* root;
     vector<int> dx = {1,-1,0,0};
    vector<int> dy = {0,0,-1,1};
    
    void insertTrie(string word, TrieNode* root)
    {
        TrieNode* curr = root;
        for(int i=0;i<word.length();i++)
        {
            int index = word[i]-'a';
            if(curr->child[index] == NULL)
                curr->child[index] = new TrieNode();
            curr= curr->child[index];
        }
        
        curr->isWord = true;
        curr->word = word;
    }
    

    void DFS(vector<vector<char>>& board, vector<string> &ans, TrieNode* temp, int i, int j)
    {
        // invalid case
        if(i<0 || i>=board.size() || j<0 || j>= board[0].size() || board[i][j] == '*' || temp->child[board[i][j] - 'a'] == NULL)
            return;
        
        // Move to next node
        temp = temp->child[board[i][j] - 'a'];
        
        // If we have reached the last char - BASE CASE
        if(temp->isWord)
        {
            ans.push_back(temp->word);
            temp->isWord = false;
        }
        
        // To ensure that char is used only once within a word
        char c = board[i][j];
        board[i][j] = '*';
        
        for(int dir = 0;dir<4;dir++)
        {
            int ni = i + dx[dir];
            int nj = j + dy[dir];
            
            DFS(board, ans, temp, ni, nj);
        }
        
        board[i][j] = c;
        return;
        
    }
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        
        // Create instance of TrieNode class
        TrieNode* root = new TrieNode();
        
        // Insert into trie
        for(auto word: words)
            insertTrie(word, root);
        
        // call DFS for all cells
        vector<string> ans;
        TrieNode* curr = root;
        for(int i=0;i<board.size();i++)
        {
            for(int j=0;j<board[0].size();j++)
            {
                DFS(board, ans, curr, i, j);
            }
        }
        return ans;
        
    }
};