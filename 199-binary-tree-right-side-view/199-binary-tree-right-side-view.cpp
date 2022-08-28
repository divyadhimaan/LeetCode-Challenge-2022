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
    
//     void solve(TreeNode* root, vector<int> &v)
//     {
//         if(!root)
//             return;
//         queue<TreeNode*> q;
//         q.push(root);
        
//         while(!q.empty())
//         {
//             int size = q.size();
//             for(int i=0;i<size;i++)
//             {
//                 TreeNode* curr = q.front();
//                 q.pop();
                
//                 if(i==size-1)
//                     v.push_back(curr->val);
                
//                 if(curr->left)
//                     q.push(curr->left);
//                 if(curr->right)
//                     q.push(curr->right);
//             }
//         }
//     }
    int maxLevel = 0;
    void solve(TreeNode* root, int level, vector<int> &v)
    {
        if(!root)
            return;
        if(level > maxLevel)
        {
            v.push_back(root->val);
            maxLevel = level;
        }
        
        
        solve(root->right, level+1, v);
        solve(root->left, level+1, v);
    }
    
    vector<int> rightSideView(TreeNode* root) {
        vector<int> v;
        solve(root, 1, v);
        return v;
    }
};