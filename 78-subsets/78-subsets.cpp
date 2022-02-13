class Solution {
public:
    vector<vector<int>> ans; // to store answer
    
    void solve(vector<int> &arr, int i, vector<int> temp)
    {
        if(i == arr.size()) // if we find out one possibility
        {
            //push into the final answer that possibility
            ans.push_back(temp); 
            return;
        }
        
        solve(arr, i + 1, temp); // finding possibility for next index
        
        temp.push_back(arr[i]); // push into the array
        
        solve(arr, i + 1, temp); //again finding out the next possibility
        
    }
    
    vector<vector<int>> subsets(vector<int>& arr) {
         vector<int> temp; // vector to store temporary answer
        
        solve(arr, 0, temp); // function that will generate our final answer
        
        return ans; // return the final answer
    }
};