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
    int findBottomLeftValue(TreeNode* root) {
        // int curr_level = 0;
        
        queue<pair<int,TreeNode*>> q;
        q.push({0,root});
        
        int ans = 0;
        int level = -1;
        
        while(!q.empty())
        {
            int size = q.size();
            for(int i=0;i<size;i++)
            {
                auto t = q.front();
                q.pop();
                int l = t.first;
                TreeNode* curr = t.second;
                
                if(i==0)
                {
                    if(level<l)
                    {
                        level = l;
                        ans = curr->val;
                    }
                }
                
                if(curr->left)
                {
                    q.push({l+1, curr->left});
                }
                if(curr->right)
                {
                    q.push({l+1, curr->right});
                }
            }
        }
        
        return ans;
    }
};