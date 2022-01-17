class Solution {
public:
    vector<int> selfDividingNumbers(int left, int right) {
        vector<int> v;
        int flag = 0;
        for(int i=left;i<=right;i++)
        {
            flag = 0;
            int n = i;
            while(n)
            {
                int digit = n%10;
                if(digit == 0 || i % digit != 0)
                    flag = 1;
                n /= 10;
            }
            if(flag == 0)
                v.push_back(i);
        }
        return v;
    }
};