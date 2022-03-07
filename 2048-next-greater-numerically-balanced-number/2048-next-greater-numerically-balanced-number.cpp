class Solution {
public:
    int nextBeautifulNumber(int n) {
        
        if(n>=666666){
            return 1224444;
        }
        
     
        
        unordered_map<int,int> mp;
        int flag;
        for(int i=n+1;i<=666666;i++){
            
            int m = i;
            
            while(m){
                int rem = m%10;
                mp[rem]++;
                m=m/10;
            }
            flag = 0;
            for(auto x : mp){
                if(x.first!=x.second){
                    flag=1;
                    mp.clear();
                    break;
                }
            }
            
            if(flag==0){
                return i;
            }
            
        }
        
        return -1;
        
    }
};