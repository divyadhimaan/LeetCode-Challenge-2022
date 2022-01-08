class Solution {
public:
    unordered_map<string,int> mp;
    int n=0;
    int getPalindromeCount(vector<string>& arr)
    {
        int count=0;
        bool flag=false;
        for(int i=0;i<n;i++)
        {
            if (arr[i][0]==arr[i][1])
            {
                if (mp[arr[i]]%2!=0)
                {
                    flag=true;
                    count=count+((mp[arr[i]]-1)*2);
                }
                else
                    count=count+(2*mp[arr[i]]);
                mp.erase(arr[i]);
            }
        }
        if (flag)
            count+=2;
        return count;
    }
    int getNonPalindromeCount(vector<string>& arr)
    {
        int count=0;
        for (int i=0;i<n;i++)
        {
            if (arr[i][0]!=arr[i][1] && mp.find(arr[i])!=mp.end())
            {
                string temp=arr[i];
                swap(temp[0],temp[1]);
                if (mp.find(temp)!=mp.end())
                {
                    count+=4;
                    mp[arr[i]]--;
                    mp[temp]--;
                    if (mp[arr[i]]==0)
                        mp.erase(arr[i]);
                    if (mp[temp]==0)
                        mp.erase(temp);
                }
            }
        }
        return count;
    }
    int longestPalindrome(vector<string>& arr)
    {
        n=arr.size();
        for (auto& i:arr)
            mp[i]++;
        
        int count1=getPalindromeCount(arr);
        int count2=getNonPalindromeCount(arr);
        return count1+count2;
    }
};