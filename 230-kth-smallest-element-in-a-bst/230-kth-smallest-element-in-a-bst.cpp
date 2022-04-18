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
    int count=0;
    TreeNode* node = NULL;
    void inOrder(TreeNode* root, int k)
    {
        if(root!=NULL)
        {
            inOrder(root->left, k);
            count++;
            if(count==k)
            {
                node = root;
                return;
            }
            inOrder(root->right, k);
        }
    }
    int kthSmallest(TreeNode* root, int k) {
        inOrder(root, k);
        return node->val;
    }
};