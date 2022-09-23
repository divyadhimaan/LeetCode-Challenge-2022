
class Solution {
public:
    
    int DFS(vector<vector<int>>& obstacleGrid, int i, int j, vector<vector<int>> &memo)
    {
        if(i<0 || i>=obstacleGrid.size() || j<0 || j>= obstacleGrid[0].size())
            return 0;
        
        if(obstacleGrid[i][j] == 1)
            return 0;
        if(memo[i][j] != -1)
            return memo[i][j];
        
        if(i == obstacleGrid.size()-1 && j==obstacleGrid[0].size()-1 && obstacleGrid[i][j]==0)
            return 1;
        
        return memo[i][j] = DFS(obstacleGrid, i+1, j, memo) + DFS(obstacleGrid, i, j+1, memo);
        
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<vector<int>> memo(m, vector<int>(n, -1));
        return DFS(obstacleGrid, 0, 0, memo);
    }
};