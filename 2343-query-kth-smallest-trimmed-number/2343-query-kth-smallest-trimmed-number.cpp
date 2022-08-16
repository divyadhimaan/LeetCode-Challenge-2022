class Solution {
public:
    vector<int> smallestTrimmedNumbers(vector<string>& nums, vector<vector<int>>& queries) {
        
        vector<int> ans;
        int n = nums.size();
        int sz = nums[0].size();
        
        for(int i=0;i<queries.size();i++)
        {
            vector<pair<string,int>> vc;
            
            for(int j=0;j<n;j++)
            {
                string str = nums[j].substr(sz - queries[i][1]);
                vc.push_back({str, j});
            }
            
            sort(vc.begin(), vc.end());
            ans.push_back(vc[queries[i][0] -1].second);
            
        }
        return ans;
    }
};