class TrieNode{
    public:
    TrieNode* child[26];
    bool isEnd;
    
    TrieNode()
    {
        isEnd = false;
        for(int i=0;i<26;i++)
        {
            child[i] = NULL;
        }
    }
};



class MagicDictionary {
public:
    TrieNode* root = new TrieNode();
    MagicDictionary() {
    }
    void insert(string s)
    {
        TrieNode* curr = root;
        for(char c: s)
        {
            int index = c-'a';
            if(curr->child[index] == NULL)
               curr->child[index] = new TrieNode();
            curr = curr->child[index];
        }
        curr->isEnd = true;
    }
    
    void buildDict(vector<string> dictionary) {
        for(string s: dictionary)
        {
            insert(s);
        }
    }
               
    bool find(string s) {
        TrieNode *temp=root;
        for(char c: s) {
            int index=c-'a';
            if(temp->child[index]==NULL) {
                return false;
            }
            temp=temp->child[index];
        }
        if(temp->isEnd==true) {
            return true;
        }
        else {
            return false;
        }
    }
    
    bool search(string s) {
        for(int i=0;i<s.length();i++)
        {
            for(int j=0;j<26;j++)
            {
                char c = j + 'a';
                if(c==s[i])
                    continue;
                swap(s[i], c);
                
                if(find(s))
                    return true;
                
                swap(s[i], c);
            }
        }
        return false;
    }
    
};

/**
 * Your MagicDictionary object will be instantiated and called as such:
 * MagicDictionary* obj = new MagicDictionary();
 * obj->buildDict(dictionary);
 * bool param_2 = obj->search(searchWord);
 */