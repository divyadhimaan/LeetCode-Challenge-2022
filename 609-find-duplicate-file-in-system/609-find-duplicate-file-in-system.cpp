
// "(root/a) (1.txt(abcd)) (2.txt(efgh))"
class Solution {
public:
    vector<vector<string>> findDuplicate(vector<string>& paths) {
        map<string, vector<pair<string, string>>> mp;
        
        for(string path: paths)
        {

            string directory = "";
            int i=0;
            for( ;i<path.length();i++)
            {
                if(path[i] == ' ')
                    break;
                directory += path[i];
            }
            
            string file, content;
            for(int k =i+1 ;k<path.length();k++)
            {
                if(path[k]==' ')
                    continue;
                
                file="",content="";
                while(path[k] != '('){
                    file+= path[k++];
                }
                k++;
                while(path[k]!=')'){
                    content += path[k++];
                }
                k++;
                mp[content].push_back({directory, file});
            }
        }
        
        vector<vector<string>> ans;
        for(auto x: mp)
        {
            if(x.second.size() >=2)
            {
                vector<string> temp;
                for(auto i: x.second)
                {
                    temp.push_back(i.first + '/' + i.second);
                    // cout<<x.first<<" "<<i.first<<" "<<i.second<<endl;
                }
                ans.push_back(temp);
            }
            
        }
        
        return ans;
    }
};