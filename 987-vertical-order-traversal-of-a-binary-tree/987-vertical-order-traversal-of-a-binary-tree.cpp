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
    
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> ans;
        
        map<int, map<int, multiset<int>>> mp; 
        
        queue<pair<TreeNode*,pair<int,int >>> q;
        q.push({root, {0,0}});
        
        while(!q.empty())
        {
            int size = q.size();
            while(size--)
            {
                int x = q.front().second.first;
                int y = q.front().second.second;
                TreeNode* curr = q.front().first;
                q.pop();
                
                mp[x][y].insert(curr->val);
                
                if(curr->left)
                    q.push({curr->left, {x-1, y+1}});
                
                if(curr->right)
                    q.push({curr->right, {x+1, y+1}});
            }
        }
        
        
        for(auto x: mp)
        {
            vector<int> temp;
            for(auto j: x.second)
                temp.insert(temp.end(), j.second.begin(), j.second.end());
            ans.push_back(temp);
        }
        return ans;
    }
};