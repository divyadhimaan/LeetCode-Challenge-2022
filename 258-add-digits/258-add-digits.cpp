class Solution {
public:
    int addDigits(int num) {
        int n = num;
        while(n/10 != 0)
        {
            int sum=0;
            while(n)
            {
                int digit = n%10;
                sum += digit;
                n=n/10;
            }
            n = sum;
        }
        return n;
    }
};