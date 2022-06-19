class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        
        sort(products.begin(), products.end());
        vector<vector<string>> ans;
        
        int l=0,r=products.size()-1;
        
        for(int i=0;i<searchWord.size();i++)
        {
            char ch=searchWord[i];
            
            vector<string> temp;
            
            while(l<=r && products[l][i]!=ch)
            {
                l++;
            }
            
            while(l<=r && products[r][i]!=ch)
            {
                r--;
            }
                
            for(int j=l;j<l+min(3,r-l+1);j++)
                temp.push_back(products[j]);
            
            ans.push_back(temp);
        }
        return ans;
    }
};