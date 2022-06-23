class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        
        vector<vector<int>> result;
        result.push_back(intervals[0]);
        
        int j=0;
        for(int i=1;i<intervals.size();i++){
            if(intervals[i][0] <= result[j][1])
                result[j][1] = max(result[j][1], intervals[i][1]);
            else{
                result.push_back(intervals[i]);
                j++;
            }   
        }
        return result;
    }
};