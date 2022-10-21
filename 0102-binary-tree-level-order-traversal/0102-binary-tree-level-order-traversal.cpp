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
    
    void solve(TreeNode *node, vector<vector<int>> &v)
    {
        if(!node)
            return;
            
        queue<TreeNode*> q;
        q.push(node);
        while(!q.empty())
        {
            vector<int> temp;
            int count = q.size();
            for(int i=0;i<count;i++)
            {
                TreeNode* curr = q.front();
                q.pop();

                temp.push_back(curr->val);

                if(curr->left)
                    q.push(curr->left);

                if(curr->right)
                    q.push(curr->right);
            }
            v.push_back(temp);
        }
    }
    
    
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> v;
        solve(root, v);
        return v;
    }
};