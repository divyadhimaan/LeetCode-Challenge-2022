class Solution {
public:
    int fillCups(vector<int>& amount) {
        priority_queue<int> pq;
        
        for(int i=0;i<amount.size();i++)
            pq.push(amount[i]);
        
        int sec = 0;
        while(true)
        {
            int num1 = pq.top();
            pq.pop();
            if(num1==0)
                break;
            int num2 = pq.top();
            pq.pop();
            
            if(num1 && num2)
            {
                pq.push(num1-1);
                pq.push(num2-1);
            }else if(num1){
                sec+= num1;
                break;
            }
            sec++;
        }
        
        return sec;
    }
};