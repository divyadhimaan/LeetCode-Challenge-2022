class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int,int> freq;
        for (int i : nums) {
            freq[i]++;
        }
        for (auto kv : freq) {
            if (kv.second == 1) {
                return kv.first;
            }
        }
        return -1;
    }
};