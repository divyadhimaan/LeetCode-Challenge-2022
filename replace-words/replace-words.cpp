class TrieNode{
    public:
    TrieNode* child[26];
    // string word;
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


class Solution {
public:
    
    void insert(TrieNode* root, string key)
    {
        TrieNode* curr = root;
        for(int i=0;i<key.length();i++)
        {
            int index = key[i] - 'a';
            if(curr->child[index] == NULL)
                curr->child[index] = new TrieNode();
            
            curr = curr->child[index];
        }
        curr->isEnd = true;
    }
    string search(TrieNode* root, string pattern)
    {
        TrieNode* curr = root;
        string res="";
        
        for(int i=0;i<pattern.length();i++)
        {
            int index = pattern[i] - 'a';
            if(curr->child[index] == NULL)
                break;
            res += pattern[i];
            curr = curr->child[index];
            if(curr->isEnd)
                return res;
        }
        return pattern;
    }
    
    
    string replaceWords(vector<string>& dictionary, string sentence) {
        
        TrieNode* root = new TrieNode();
        
        for(int i=0;i<dictionary.size();i++)
        {
            insert(root,dictionary[i]);
        }
        
        istringstream ss(sentence);
        string word = "", ans="";
        
        for(; ss>>word; ){
            ans += search(root,word);
            ans += ' ';
        }
        ans.pop_back();
        
        return ans;
    }
};