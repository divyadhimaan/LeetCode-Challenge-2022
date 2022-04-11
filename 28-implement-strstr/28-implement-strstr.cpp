class Solution {
public:
    int strStr(string haystack, string needle) {
        if (needle.size() == 0) return 0;
        if (needle.length() > haystack.length()) return -1;

        for (int i = 0; i < haystack.length(); i++)
        {
            if (haystack.substr(i, needle.length()).compare(needle) == 0)
                return i;
        }
        return -1;
    }
};