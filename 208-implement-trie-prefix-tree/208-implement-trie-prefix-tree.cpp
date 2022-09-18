
class TrieNode {
public:
    // Initialize your data structure here.
    bool isEnd;
    TrieNode *children[26];
    
    TrieNode() {
        isEnd = false;
        
        for (int i = 0; i < 26; i++)
            children[i] = NULL;
    }
};

class Trie {
private:
    TrieNode *root;
public:
    Trie() {
        root = new TrieNode();
    }
    
    void insert(string word) {
        TrieNode* curr = root;
        for(int i=0;i<word.length();i++)
        {
            int index = word[i] - 'a';
            if(curr->children[index] == NULL)
                curr->children[index] = new TrieNode();
            curr = curr->children[index];
        }
        curr->isEnd = true;
    }
    
    bool search(string word) {
        TrieNode* curr = root;
        for(int i=0;i<word.length();i++)
        {
            int index = word[i] - 'a';
            if(curr->children[index] == NULL)
                return false;
            curr = curr->children[index];
        }
        return curr->isEnd;
    }
    
    bool startsWith(string prefix) {
        TrieNode* curr = root;
        for(int i=0;i<prefix.length();i++)
        {
            int index = prefix[i] - 'a';
            if(curr->children[index] == NULL)
                return false;
            curr = curr->children[index];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */