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
    
    void findPath(TreeNode* root, vector<string> &ans, string t)
    {
        if(!root->left && !root->right)
        {
            ans.push_back(t);
            return;                
        }
        
        if(root->left)
            findPath(root->left, ans, t + "->" + to_string(root->left->val));
        if(root->right)
            findPath(root->right, ans, t + "->" + to_string(root->right->val));
    }
    
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
        
        if(!root)
            return ans;
        
        findPath(root, ans, to_string(root->val));
        return ans;
    }
};