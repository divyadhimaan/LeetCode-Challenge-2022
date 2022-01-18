class Solution {
public:
    bool canPlaceFlowers(vector<int>& v, int n) {
		if(n==0){
			return true;
		}
    
    int size = v.size();
    
    if(size==1 && n==1){
        if(v[0]==0){
            return true;
        }else{
            return false;
        }
    }
    
    for(int i=0;i<size;i++){
       if(v[i]==1){
           continue;
       }else{
           if(i==0){
               if(v[i+1]!=1){
                   v[i]=1;
                   n--;
               }
           }else if(i==size-1){
               if(v[i-1]!=1){
                   v[i]=1;
                   n--;
               }
           }else{
                if(v[i-1]!=1 && v[i+1]!=1){
                   v[i]=1;
                   n--;
                }
           }
        
    }
        if(n==0){
            break;
        }
    }
    
    if(n!=0){
        return false;
    }else{
        return true;
    }
  }
};