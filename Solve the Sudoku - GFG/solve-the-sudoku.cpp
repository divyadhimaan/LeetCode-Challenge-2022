// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
// UNASSIGNED is used for empty cells in sudoku grid 
#define UNASSIGNED 0  

// N is used for the size of Sudoku grid.  
// Size will be NxN  
#define N 9  


 // } Driver Code Ends
class Solution 
{
    public:
    
    bool isSafe(int grid[N][N], int row, int col, int num)
    {
        // check for column
        for(int i=0;i<N;i++)
        {
            if(grid[i][col]==num)
                return false;
        }
        
        // check for row
        for(int j=0;j<N;j++)
        {
            if(grid[row][j]==num)
                return false;
        }
        
        int s = sqrt(N);
        int rowStart = row - (row%s);
        int colStart = col - (col%s);
        
        for(int r = rowStart; r < rowStart + s; r++)
        {
            for(int d = colStart; d < colStart + s; d++)
            {
                if(grid[r][d] == num)
                    return false;
            }
        }
        return true;
    }
    
    //Function to find a solved Sudoku. 
    bool SolveSudoku(int grid[N][N])  
    { 
        int row = -1;
        int col = -1;
        bool isEmpty = true;
        
        // find empty cell
        for(int i=0;i<N;i++)
        {
            for(int j=0;j<N;j++)
            {
                if(grid[i][j] == 0)
                {
                   row = i;
                   col = j;
                   isEmpty = false;
                   break;
                }
            }
            if(!isEmpty)
                break;
        }
        
        
        if(isEmpty)
            return true;
            
        for(int num=1;num<=N;num++)
        {
            if(isSafe(grid, row, col, num))
            {
                grid[row][col] = num;
                if(SolveSudoku(grid))
                    return true;
                grid[row][col] = 0;
            }
        }
        return false;
    }
    
    //Function to print grids of the Sudoku.
    void printGrid (int grid[N][N]) 
    {
        for(int i=0;i<N;i++)
        {
            for(int j=0;j<N;j++)
            {
                cout<<grid[i][j]<<" ";
            }
        }
    }
};

// { Driver Code Starts.

int main() {
	int t;
	cin>>t;
	while(t--)
	{
		int grid[N][N];
		
		for(int i=0;i<9;i++)
		    for(int j=0;j<9;j++)
		        cin>>grid[i][j];
		        
		Solution ob;
		
		if (ob.SolveSudoku(grid) == true)  
            ob.printGrid(grid);  
        else
            cout << "No solution exists";  
        
        cout<<endl;
	}
	
	return 0;
}  // } Driver Code Ends