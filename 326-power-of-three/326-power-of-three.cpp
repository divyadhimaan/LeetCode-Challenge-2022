class Solution {
public:
    bool isPowerOfThree(int n) {
        if(n==1)
            return 1;
        else if(n==0 || n%3!=0)
            return 0;
        else
            return isPowerOfThree(n/3);
    }
};