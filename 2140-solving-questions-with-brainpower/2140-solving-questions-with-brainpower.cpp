class Solution {
public:
    long long solve(vector<vector<int>> &ques, int curr, vector<long long> &memo)
    {
            
        if(curr >= ques.size())
            return 0; 
        
        if(memo[curr] != 0)
            return memo[curr];
        
        long long points = ques[curr][0];
        memo[curr] = max(points + solve(ques, curr+ques[curr][1]+1, memo), solve(ques, curr+1, memo));
        
        return memo[curr];
        
    }
    
    long long mostPoints(vector<vector<int>>& questions) {
        vector<long long> memo(questions.size(), 0);
        return solve(questions,0, memo);
    }
};