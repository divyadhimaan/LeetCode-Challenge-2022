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
    
    int findLength(TreeNode* root, int &ans)
    {
        if(!root)
            return 0;
        
        int l = findLength(root->left, ans);
        int r = findLength(root->right, ans);
    
        int ll = 0;
        int rl = 0;
        if(root->left && root->left->val == root->val)
            ll += l + 1;
        if(root->right && root->right->val == root->val)
            rl += r + 1;
        
        ans =  max(ans, rl + ll);
        
        return max(rl,ll);
        
    }
    
    int longestUnivaluePath(TreeNode* root) {
        int ans=0;
        findLength(root, ans);
        return ans;
    }
};