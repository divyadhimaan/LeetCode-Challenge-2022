class Solution {
public:
    int arrangeCoins(int n) {
        int i=1;
        long long ans = 0; // for calculation prefix sum
        int count=0;
        while(1)
        {
            ans = ans + i;
            if(ans<=n) // as soon as out ans greater than n we terminate the loop indicate incomplte row
                count+=1;
            else
                break;
            i++;
        }
        return count;
    }
};