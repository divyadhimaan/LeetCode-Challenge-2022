class TrieNode {
public:
    int score;
    TrieNode* child[26];
    
    
    TrieNode()
    {
        score= 0;
        for(int i=0;i<26;i++)
            child[i] = NULL;
    }
};

class MapSum {
public:
    int res = 0;
    TrieNode *root = new TrieNode();
    MapSum() {
        
    }
    
    void insert(string key, int val) {
        TrieNode* curr = root;
        
        for(int i=0;i<key.length();i++)
        {
            int index = key[i] - 'a';
            if(curr->child[index] == NULL)
            {
                curr->child[index] = new TrieNode();
            }
            curr = curr->child[index];
        }
        curr->score = val;
    }
    
    void calc(TrieNode* curr) {
        res += curr->score;
        for (int i = 0; i < 26; i++) {
            if (curr->child[i]) {
                calc(curr->child[i]);
            }
        }
    }
    
    int sum(string prefix) {
        res = 0;
        TrieNode* curr = root;
        
        for(int i=0;i<prefix.length();i++)
        {
            int index = prefix[i] - 'a';
            if(curr->child[index] == NULL)
            {
                return 0;
            }
            curr = curr->child[index];
        }
        calc(curr);
        return res;
    }
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum* obj = new MapSum();
 * obj->insert(key,val);
 * int param_2 = obj->sum(prefix);
 */