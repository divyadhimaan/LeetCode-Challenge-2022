class Solution {
public:
    int strStr(string haystack, string needle) {
        if (needle.size() == 0) return 0;
        if (needle.length() > haystack.length()) return -1;

        for (int i = 0; i <= haystack.length() - needle.length(); i++) {
          if (strncmp(haystack.c_str() + i, needle.c_str(), needle.length()) == 0) {
            return i;
          }
        }
        return -1;
    }
};