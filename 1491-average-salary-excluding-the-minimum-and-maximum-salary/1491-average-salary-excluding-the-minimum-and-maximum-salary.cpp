class Solution {
public:
    double average(vector<int>& salary) {
        double sum = 0;
        int mini = INT_MAX, maxi = INT_MIN;
        
        for(int i=0;i<salary.size();i++)
        {
            sum += (double)salary[i];
            if(salary[i] < mini)
                mini = salary[i];
            if(salary[i] > maxi)
                maxi = salary[i];
        }
        double res = (sum - (maxi + mini))/(salary.size()-2);
        return res;
    }
};