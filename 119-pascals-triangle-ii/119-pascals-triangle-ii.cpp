class Solution {
public:
    
    vector<int> constructPascal(int rowIndex)
    {
        vector<vector<int>> p;
        for(int i=0;i<=rowIndex;i++)
        {
            vector<int> temp;
            for(int j=0;j<=i;j++)
            {
                if(j==0 || j==i)
                    temp.push_back(1);
                else{
                    temp.push_back(p[i-1][j-1] + p[i-1][j]);
                }
            }
            p.push_back(temp);
        }
        return p[rowIndex];
    }
    
    vector<int> getRow(int rowIndex) {
        vector<int> ans;
        ans = constructPascal(rowIndex);
        return ans;
    }
};