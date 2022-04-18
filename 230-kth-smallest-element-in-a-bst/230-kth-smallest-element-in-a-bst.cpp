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
    void inOrder(TreeNode* root, stack<int> &st)
    {
        if(root!=NULL)
        {
            inOrder(root->left, st);
            st.push(root->val);
            inOrder(root->right, st);
        }
    }
    int kthSmallest(TreeNode* root, int k) {
        stack<int> st;
        inOrder(root, st);
        
        int n = st.size();
        for(int i=0;i<n-k;i++)
        {
            st.pop();
        }
        return st.top();
    }
};