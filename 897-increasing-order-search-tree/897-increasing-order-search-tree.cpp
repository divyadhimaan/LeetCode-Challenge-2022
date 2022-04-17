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
    TreeNode* prev = NULL;
    void inOrder(TreeNode* root, TreeNode* dummy)
    {
        if(root!=NULL)
        {
            inOrder(root->left, dummy);
            if(prev == NULL)
            {
                TreeNode* root_node = new TreeNode(root->val);
                dummy->right = root_node;
                prev = root_node;
            } else {
                TreeNode* node = new TreeNode(root->val);
                prev->right = node;
                prev = node;
            }
            inOrder(root->right, dummy);
        }
    }
    
    TreeNode* increasingBST(TreeNode* root) {
        if(!root)
            return root;
        TreeNode* dummy = new TreeNode(-1);
        inOrder(root, dummy);
        return dummy->right;
    }
};