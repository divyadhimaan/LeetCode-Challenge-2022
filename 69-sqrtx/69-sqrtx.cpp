class Solution {
public:
    int mySqrt(int x) {
        if(x == 0) return 0;
        long long start=0,end=(x/2)+1;   //use long to avoid integer overflow
        long long mid=start + (end-start)/2;
        long long res=-1;
        
        while(start<=end)
        {
            long long square = mid*mid;
            if(square == x)
            {
                return mid;
            }
            if(square < x)
            {
                res = mid;
                start=mid+1;
            }
            if(square > x)
            {
                end = mid-1;
            }
            mid = start+(end-start)/2;
        }
        return res;
    }
};