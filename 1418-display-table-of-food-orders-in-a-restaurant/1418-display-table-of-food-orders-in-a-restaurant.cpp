class Solution {
public:
    
    static bool cmp(vector<string> &a, vector<string> &b)
    {
        return stoi(a[0]) < stoi(b[0]);
    }
    
    vector<vector<string>> displayTable(vector<vector<string>>& orders) {
        set<string> tables;
        set<string> foods;
        
        for(auto x: orders)
        {
            string table_name = x[1];
            string food_item = x[2];
            tables.insert(table_name);
            foods.insert(food_item);
        }
        
        vector<vector<string>> ans(tables.size()+1, vector<string> (foods.size()+1, "0"));
        ans[0][0] = "Table";
        int i=1;
        
        map<string,int> mp;
        for(auto x: foods)
        {
            ans[0][i] = x;
            mp[x] = i;
            i++;
        }
        
        map<string,map<string,int>> m;
        for(auto x : orders)
        {
            string table_name = x[1];
            string food_item = x[2];
            m[table_name][food_item]++;
        }
        i=1;
        for(auto x: m)
        {
            ans[i][0] = x.first;
            for(auto y: x.second)
            {
                ans[i][mp[y.first]] = to_string(y.second);
            }
            i++;
        }
        
        sort(ans.begin()+1, ans.end(), cmp);
        
        return ans;
        
    }
};