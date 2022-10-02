class Solution {
public:
    int dp[25][35];
    bool check(string &s, string &p, int i, int j, int &m, int &n) {
        if(i == m && j == n) 
            return true;
        if(j == n) 
            return false;
        if(dp[i][j] != -1) 
            return dp[i][j];
        bool valid = (i < m) && (s[i] == p[j] || p[j] == '.');
        if(j+1 < n && p[j+1] == '*') {
            return dp[i][j] = check(s, p, i, j+2, m, n) || valid && check(s, p, i+1, j, m, n);
        }
        if(valid) {
            return dp[i][j] = check(s, p, i+1, j+1, m, n);
        }
        return dp[i][j] = false;
    }
    bool isMatch(string s, string p) {
        int m = s.length(), n = p.length();
        memset(dp, -1, sizeof(dp));
        return check(s, p, 0, 0, m, n);
    }
};