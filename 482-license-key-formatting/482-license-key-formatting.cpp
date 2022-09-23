class Solution {
public:
    string licenseKeyFormatting(string s, int K) {
        string res;
        for (auto i = s.rbegin(); i < s.rend(); i++)
        if (*i != '-') { // ignore '-' in original string
          if (res.size()%(K+1) == K) 
              res += '-'; // every (K+1)th char is '-' from tail
          res += toupper(*i);
        }

        reverse(res.begin(), res.end());
        return res;
    }
};