class Solution {
public:
    int calculateHistogram(vector<int> h)
    {
        stack<int> st;
        int leftSmall[h.size()];
        int rightSmall[h.size()];
        
        for(int i=0;i<h.size();i++)
        {
            while(!st.empty() && h[st.top()] > h[i])
                st.pop();
            
            if(st.empty())
                leftSmall[i] = 0;
            else
                leftSmall[i] = st.top() +1;
            
            st.push(i);
        }
        
        while(!st.empty())
            st.pop();
        
        for(int i=h.size()-1;i>=0;i--)
        {
            while(!st.empty() && h[st.top()] >= h[i])
                st.pop();
            
            if(st.empty())
                rightSmall[i] = h.size() - 1;
            else
                rightSmall[i] = st.top() - 1;
            
            st.push(i);
        }
        
        int maxArea = 0;
        for(int i=0;i<h.size();i++)
        {
            maxArea = max(maxArea, ((rightSmall[i] - leftSmall[i] + 1)* h[i]));
        }
        return maxArea;
    }
    
    int maximalRectangle(vector<vector<char>>& matrix) {
        
        int maxArea = 0;
        vector<int> heights(matrix[0].size());
        for(int i =0;i<matrix.size();i++)
        {
            for(int j=0;j<matrix[0].size();j++)
            {
                if(matrix[i][j] == '0')
                    heights[j] = 0;
                else
                    heights[j]++;
            }
            maxArea= max(maxArea, calculateHistogram(heights));
        }
        
        return maxArea;
    }
};