class Solution {
public:
    int parent[26];
    int find(int c)
    {
        if(c == parent[c])
            return c;
        
        return parent[c] = find(parent[c]);
    }
    bool equationsPossible(vector<string>& equations) {
        for(int i=0;i<26;i++)
            parent[i] = i;
        
        for(auto e: equations)
        {
            if(e[1] == '=')
                parent[find(e[0] - 'a')] = find(e[3] - 'a');
        }
        for(auto e: equations)
        {
            if(e[1] == '!')
                if(find(e[0] - 'a') == find(e[3] - 'a'))
                    return false;
        }
        return true;
    }
};