class Solution {
public:
    
    static int countSetBits(int n)
    {
        int count = 0;
        while(n){
            n = n&(n-1);
            count++;
        }
        return count;
    }
    static bool cmp(int a, int b)
    {
        int p = countSetBits(a);
        int q = countSetBits(b);
        
        if(p==q)
            return a<=b;
        else
            return p<q;
    }
    
    vector<int> sortByBits(vector<int>& arr) {
        sort(arr.begin(), arr.end(), cmp);
        return arr;
    }
};
    