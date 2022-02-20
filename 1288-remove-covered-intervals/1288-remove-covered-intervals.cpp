class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        
        int max_left = -1, max_right = -1, ans=0;
        
        for(int i=0;i<intervals.size();i++)
        {
            if(intervals[i][0] > max_left && intervals[i][1] > max_right)
            {
                ans++;
                max_left = intervals[i][0];
            }
            max_right = max(max_right, intervals[i][1]);
        }
        return ans;
    }
};