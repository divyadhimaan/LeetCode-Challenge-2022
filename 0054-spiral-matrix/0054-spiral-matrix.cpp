class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int top = 0;
        int bottom = matrix.size();
        int left = 0;
        int right = matrix.front().size();
        
        vector<int> res;
        while( true ) {
            for( int i = left; i < right; ++i )
                res.push_back( matrix[top][i] );
            
            if( ++top == bottom ) break;
            
            for( int i = top; i < bottom; ++i )
                res.push_back( matrix[i][right-1] );
            
            if( --right == left ) break;
            
            for( int i = right; i > left; --i )
                res.push_back( matrix[bottom-1][i-1] );
            
            if( --bottom == top ) break;
            
            for( int i = bottom; i > top; --i )
                res.push_back( matrix[i-1][left] );
            
            if( ++left == right ) break;
        }
        return res;
    }
};