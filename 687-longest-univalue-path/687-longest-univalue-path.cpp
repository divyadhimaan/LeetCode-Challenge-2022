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
    int ans=0;
    int solve(TreeNode* root)
    {
        if(!root)
            return 0;
        
        int l = solve(root->left);
        int r = solve(root->right);
        
        int ll=0,rr=0;
        if(root->left && root->val == root->left->val)
            ll += l + 1;
        
        if(root->right && root->val == root->right->val)
            rr += r + 1;
        
        ans = max(ans, ll+rr);
        
        return max(ll,rr);
    }
    
    int longestUnivaluePath(TreeNode* root) {
        solve(root);
        return ans;
    }
};