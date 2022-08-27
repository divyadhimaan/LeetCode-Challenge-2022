class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int start =0, end=0;
        unordered_map<int, int> freq_map;
        int max_fruit = INT_MIN;

        while(end<fruits.size())
        {
            freq_map[fruits[end]]++;
            while(freq_map.size() > 2)
            {
                freq_map[fruits[start]]--;
                if(freq_map[fruits[start]] ==0)
                    freq_map.erase(fruits[start]);
                start++;
            }
            max_fruit = max(max_fruit, end-start+1);
            end++;
        }
        return max_fruit;
    }
};