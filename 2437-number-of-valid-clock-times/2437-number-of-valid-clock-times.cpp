class Solution {
public:
    int countTime(string time) {
        int ans = 1;
        if (time[0] == '?') {
            if (time[1] == '?') {
                ans *= 24;
            } else if (time[1] <= '3') {
                ans *= 3;
            } else {
                ans *= 2;
            }
        } else if (time[1] == '?') {
            ans *= time[0] < '2' ? 10 : 4;
        }
        if (time[3] == '?') 
            ans *= 6;
        if (time[4] == '?') 
            ans *= 10;
        return ans;
    }
};