class Solution {
public:
    
    int binomialCoeff(int n, int k)
    {
        int res = 1;
        if (k > n - k)
        k = n - k;
        for (int i = 0; i < k; ++i)
        {
            res *= (n - i);
            res /= (i + 1);
        }
        return res;
    }

    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> result;
        int cols = 1;
        for(int i=0;i<numRows; i++)
        {
            vector<int> temp;
            for(int j=0;j<cols;j++)
            {
                int ans = binomialCoeff(i,j);
                temp.push_back(ans);
            }
            result.push_back(temp);
            cols++;
        }
        
        return result;
    }
};