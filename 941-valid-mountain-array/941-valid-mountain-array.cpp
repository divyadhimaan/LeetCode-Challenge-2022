class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        
        int length = arr.size();
        int i = 0;
        
        if(length < 3)
            return false;
        
        while (i < length - 1 && arr[i] < arr[i + 1])
        {
             i++;
        }
        if (i == length - 1 || i == 0)
        {
             return false;
        }
        
        while (i < length - 1 && arr[i] > arr[i + 1])
        {
             i++;
        }
        if (i == length - 1)
        {
             return true;
        }
        else
        {
             return false;
        }
        
    }
};