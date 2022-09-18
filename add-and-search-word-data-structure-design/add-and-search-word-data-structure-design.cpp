class TrieNode{
  public:
    TrieNode* child[26];
    bool isEnd;
    
    TrieNode()
    {
        isEnd = false;
        for (int i = 0; i < 26; i++)
            child[i] = NULL;
    }
};

class WordDictionary {

public:
    TrieNode* root = new TrieNode();
    WordDictionary() {
        
    }
    
    void addWord(string word) {
        TrieNode* curr = root;
        for(int i=0;i<word.length();i++)
        {
            int index = word[i] - 'a';
            if(curr->child[index] == NULL)
                curr->child[index] = new TrieNode();
            curr = curr->child[index];
        }
        curr->isEnd = true;
    }
    bool isFound(string &s, TrieNode *node, int it){ 
            if(!node)
                return false;                         
            if(it==s.size()){
                return node->isEnd;
            }
            if(s[it]!='.'){
                return isFound(s,node->child[s[it]-'a'], it+1);
            }else{
                for(int i=0;i<26;i++){ 
                    if(isFound(s, node->child[i], it+1)){
                        return true;
                    }
                }
                return false; 
            }
        }
    bool search(string word) {
        return isFound(word, root, 0);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */