class Solution {
    
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> matrix(n, vector<int>(n, 0));
        
        int top = 0;
        int bottom = n - 1;
        int left = 0;
        int right = n - 1;
        int dir = 0; 
        int curr = 1;
        
        while(top <= bottom && left <= right) {
            if(dir == 0) {
                for(int c = left; c <= right; c++) {
                    matrix[top][c] = curr++;
                }
                dir++;
                top++;
            } else if (dir == 1) {
                for(int r = top; r <= bottom; r++) {
                    matrix[r][right] = curr++;
                }
                dir++;
                right--;
            } else if (dir == 2) {
                for(int c = right; c >= left; c--) {
                    matrix[bottom][c] = curr++;
                }
                dir++;
                bottom--;
            } else if (dir == 3) {
                for(int r = bottom; r >= top; r--){
                    matrix[r][left] = curr++;
                }
                dir = 0;
                left++;
            }
        }      
        return matrix;
    }
};