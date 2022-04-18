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
    void inOrder(TreeNode* root, vector<int> &v)
    {
        if(root!=NULL)
        {
            inOrder(root->left, v);
            v.push_back(root->val);
            inOrder(root->right, v);
        }
    }
    int kthSmallest(TreeNode* root, int k) {
        vector<int> v;
        inOrder(root, v);
        return v[k-1];
        // int n = st.size();
        // for(int i=0;i<n-k;i++)
        // {
        //     st.pop();
        // }
        // return st.top();
    }
};