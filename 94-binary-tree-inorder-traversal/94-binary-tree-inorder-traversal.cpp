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
    void inorder(TreeNode *A, vector<int> &v)
    {
        if(A==NULL)
            return;

        inorder(A->left, v);
        v.push_back(A->val);
        inorder(A->right, v);
    }
    
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> v;
        inorder(root, v);
        return v;
    }
};