class TrieNode{
public:
    TrieNode *child[2];
    
    TrieNode(){
        child[0] = NULL; //for 0 bit 
        child[1] = NULL; //for 1 bit
    }
};

class Solution {
public:
    // TrieNode * root, 
    
    void insert(TrieNode * root, int x)
    {
        TrieNode* curr = root;
        bitset<32> bs(x);
        
        for(int i=31;i>=0;i--)
        {
            if(curr->child[bs[i]] == NULL)
                curr->child[bs[i]] = new TrieNode();
            
            curr = curr->child[bs[i]];
        }
    }
    
    int maxXor(TrieNode * root,int n)
    {
        TrieNode *curr = root;
        bitset<32> bs(n);
        
        int ans=0; 
        for(int j=31; j>=0; j--)
        {
            if(curr->child[!bs[j]]) 
            {
                ans += (1<<j);
                curr = curr->child[!bs[j]]; //Since 1^0 = 1 & 1^1 = 0, 0^0 = 0
            }
            else 
                curr = curr->child[bs[j]];
        }
        return ans;
    }
    
    int findMaximumXOR(vector<int>& nums) {
        TrieNode* root = new TrieNode();
        
        for(auto n: nums)
        {
            insert(root,n);
        }
        
        int ans=0;
        for(auto n:nums)
        {
            ans = max(ans, maxXor(root,n));
        }
        return ans;
    }
};