class myCmp{
    public:
    bool operator()(pair<int,string> a, pair<int,string> b) const{
        if(a.first < b.first) return true;
        else if(a.first == b.first && a.second>b.second) return true;
        return false;
    }
};

class Solution {
public:
    
//     static bool myCmp(pair<int,string> &p1, pair<int,string> &p2)
//     {
//         if(p1.first == p2.first)
//             return p1.second < p2.second;
        
//         return p1.first > p2.first;
//     }
    
    vector<string> topKFrequent(vector<string>& words, int k) {
        priority_queue<pair<int, string>, vector<pair<int, string>>, myCmp> pq;
        unordered_map<string,int> mp;
        
        for(string word: words)
        {
            mp[word]++;
        }
        for(auto x: mp)
        {
            pq.push({x.second, x.first});
        }
        
        vector<string> res;
        for(int i=0;i<k;i++)
        {
            string str = pq.top().second;
            pq.pop();
            res.push_back(str);
        }
        // reverse(res.begin(), res.end());
        return res;
    }
};