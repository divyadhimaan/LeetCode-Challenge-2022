class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        int N = seats.size();
        int prev = -1, future = 0;
        int ans = 0;

        for (int i = 0; i < N; ++i) {
            if (seats[i] == 1) {
                prev = i;
            } else {
                while (future < N && seats[future] == 0 || future < i)
                    future++;

                int left = prev == -1 ? N : i - prev;
                int right = future == N ? N : future - i;
                ans = max(ans, min(left, right));
            }
        }

        return ans;
    }
};