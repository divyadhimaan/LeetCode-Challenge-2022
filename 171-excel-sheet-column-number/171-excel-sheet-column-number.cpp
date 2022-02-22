class Solution {
public:
    int titleToNumber(string columnTitle) {
        
        int n = columnTitle.length(); // extracting length of the string
    
        if(n == 1) // if length is only 1
        {
            return (columnTitle[0] - 'A') + 1; //then return only that position
        }
        
        int increase = 0; // variable used to increase the multiplcation
        int ans = 0; // variable used to store answer
        
        for(int i = n - 1; i >= 0; i--) // start traversing string from back
        {
            int pos = (columnTitle[i] - 'A') + 1; // extracting position
            
            ans = ans + (pos * pow(26, increase)); // with base 26, do further calculation
            increase++; // increase variable
        }
        
        return ans; // finally return the answer
    }
};