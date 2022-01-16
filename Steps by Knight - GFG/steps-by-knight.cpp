// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

class Solution 
{
    public:
    //Function to find out minimum steps Knight needs to reach target position.
	int minStepToReachTarget(vector<int>&KnightPos,vector<int>&TargetPos,int N)
	{
	    vector<int>board[N];
	   // board[i][j] = 0 -> not visited | else visited
	    for(int i = 0; i < N; i++){
	        board[i] = vector<int>(N, 0);
	    }
	    int s_x = KnightPos[0] - 1, s_y = KnightPos[1] - 1;
	    int t_x = TargetPos[0] - 1, t_y = TargetPos[1] - 1;
	    if(s_x == t_x && s_y == t_y){
	        return 0;
	    }
	    board[s_x][s_y] = 1;
	    queue<pair<int, int>>q;
	    q.push({s_x, s_y});
	    int steps = 0;
	    while(!q.empty()){
	        int q_size = q.size();
	        for(int i = 0; i < q_size; i++){
    	        int x = q.front().first, y = q.front().second;
    	        q.pop();
    	        vector<int> arr_x = {x + 2, x + 2, x - 2, x - 2, 
    	        x - 1, x + 1, x - 1, x + 1};
    	        vector<int> arr_y = {y - 1, y + 1, y - 1, y + 1, 
    	        y + 2, y + 2, y - 2, y - 2};
    	        for(int j = 0; j < arr_x.size(); j++){
    	            int x1 = arr_x[j], y1 = arr_y[j];
    	            if(x1 == t_x && y1 == t_y){
    	                return steps + 1;
    	            }
    	            if(x1 < N && x1 >= 0 && y1 < N && y1 >= 0 && 
    	            board[x1][y1] == 0){
        	            board[x1][y1] = 1;
        	            q.push({x1, y1});
        	        }
    	        }
	        }
	        steps++;
	    }
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		vector<int>KnightPos(2);
		vector<int>TargetPos(2);
		int N;
		cin >> N;
		cin >> KnightPos[0] >> KnightPos[1];
		cin >> TargetPos[0] >> TargetPos[1];
		Solution obj;
		int ans = obj.minStepToReachTarget(KnightPos, TargetPos, N);
		cout << ans <<"\n";
	}
	return 0;
}  // } Driver Code Ends