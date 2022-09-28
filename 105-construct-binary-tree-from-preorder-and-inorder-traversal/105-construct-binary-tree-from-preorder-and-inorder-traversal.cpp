/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int preIndex = 0;
    
    TreeNode* cTree(vector<int> &preorder, vector<int> &inorder, int i, int j)
    {
        if(i>j)
            return NULL;
        
        TreeNode* root = new TreeNode(preorder[preIndex++]);
        
        int inIndex = 0;
        for(int ind=i;ind<=j;ind++)
        {
            if(inorder[ind] == root-> val)
            {
                inIndex = ind;
                break;
            }
        }
        
        root->left = cTree(preorder, inorder, i, inIndex-1);
        root->right = cTree(preorder, inorder, inIndex+1, j);
        
        return root;
    }
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        
        int n = preorder.size();
        return cTree(preorder, inorder, 0, n-1);
        
    }
};