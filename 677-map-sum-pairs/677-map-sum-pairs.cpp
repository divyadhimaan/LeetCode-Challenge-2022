
class TrieNode
{
    public:
    TrieNode* child[26];
    // bool isEnd;
    int value;
    
    TrieNode()
    {
        value =0;
        // isEnd = false;
        for(int i=0;i<26;i++)
        {
            child[i] = NULL;
        }
    }
};

class MapSum {
public:
    TrieNode* root = new TrieNode();
    MapSum() {
        
    }
    
    void insert(string key, int val) {
        TrieNode* curr = root;
        
        for(int i=0;i<key.length();i++)
        {
            int index = key[i] - 'a';
            if(curr->child[index] == NULL)
                curr->child[index] = new TrieNode;
            curr=curr->child[index];
        }
        curr->value = val;
        // curr->isEnd = true;
        
    }
    int res =0;
    void cal(TrieNode* curr)
    {
        res += curr->value;
        for(int i=0;i<26;i++)
        {
            if(curr->child[i])
                cal(curr->child[i]);
        }
        
    }
    
    int sum(string prefix) {
        res=0;
        TrieNode* curr = root;
        
        for(int i=0;i<prefix.length();i++)
        {
            int index = prefix[i] - 'a';
            if(curr->child[index] == NULL)
                return 0;
            curr=curr->child[index];
        }
          
        cal(curr);
        
        return res;
    }
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum* obj = new MapSum();
 * obj->insert(key,val);
 * int param_2 = obj->sum(prefix);
 */