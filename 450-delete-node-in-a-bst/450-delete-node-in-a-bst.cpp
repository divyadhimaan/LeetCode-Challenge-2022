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
    
    TreeNode* succ(TreeNode* root)
    {
        root=root->right;
        while(root && root->left)
            root=root->left;
        return root;
    }
    
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(!root)
            return root;
        if(root->val < key)
            root->right = deleteNode(root->right, key);
        else if(root->val > key)
            root->left = deleteNode(root->left, key);
        else{
            if(!root->left)
            {
                TreeNode* curr = root->right;
                delete root;
                return curr;
            }
            else if(!root->right)
            {
                TreeNode* curr = root->left;
                delete root;
                return curr;
            }
            else {
                TreeNode* suc = succ(root);
                root->val = suc->val;
                root->right = deleteNode(root->right, suc->val);
            }
        }
        return root;
    }
};