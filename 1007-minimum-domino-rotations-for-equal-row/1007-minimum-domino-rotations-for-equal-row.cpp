class Solution {
public:
    
    int rotation(vector<int>& tops, vector<int>& bottoms)
    {
        int minRotations = INT_MAX;
        for(int i=1;i<=6;i++)
        {
            int swap=0,j;
            for(j=0;j<tops.size();j++)
            {
                if(tops[j] == i)
                    continue;
                else if(bottoms[j] == i)
                    swap++;
                else
                    break;
            }
            if(j==tops.size() && minRotations > swap)
                minRotations = swap;
        }
        return minRotations==INT_MAX ? -1 : minRotations;
    }
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        int a = rotation(tops,bottoms);
        
        int b = rotation(bottoms, tops);
            
        return a == -1 ? b : b == -1 ? a : min(a,b);
    }
};