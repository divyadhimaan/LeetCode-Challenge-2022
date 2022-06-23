class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        
        vector<vector<int>> res;
        if(intervals.size() == 0){
            return res;
        }
        sort(intervals.begin(),intervals.end());
        vector<int> v;
        v = intervals[0];
        
        for(auto it: intervals){
            if(it[0] <= v[1]){
                v[1] = max(v[1],it[1]);
            }else{
                res.push_back(v);
                v = it;
            }
        }
        
        res.push_back(v);
        return res;
        
    }
};