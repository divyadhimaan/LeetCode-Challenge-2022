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
    
    void Inorder(TreeNode* node,vector<int>& v)
    {
        if (node == NULL)return;

        Inorder(node->left,v);
        v.push_back(node->val);
        Inorder(node->right,v);
    }
    
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> v1;
        Inorder(root1,v1);        
        vector<int> v2;
        Inorder(root2,v2);
    
        vector<int> ans(v1.size()+v2.size());
        merge(v1.begin(),v1.end(),v2.begin(),v2.end(),ans.begin());
        return ans;
    }
    
    // void inOrder(TreeNode* root, vector<int>& sorted) {
    //     if(root == NULL) return;
    //     inOrder(root->left, sorted);
    //     sorted.push_back(root->val);
    //     inOrder(root->right, sorted);
    // }
    // vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
    //     vector<int> sorted1;
    //     vector<int> sorted2;
    //     inOrder(root1, sorted1);
    //     inOrder(root2, sorted2);
    //     vector<int> ans(sorted1.size() + sorted2.size());
    //     merge(sorted1.begin(), sorted1.end(),
    //           sorted2.begin(), sorted2.end(), ans.begin());
    //     return ans;
    // }
};