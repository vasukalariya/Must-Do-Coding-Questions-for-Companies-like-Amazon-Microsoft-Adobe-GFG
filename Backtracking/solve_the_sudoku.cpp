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
    //Function to find a solved Sudoku. 
    
    bool safe(int i, int j, int n, int grid[N][N]){
        
        for(int k = 0;k < N;k++) if(grid[i][k] == n || grid[k][j] == n) return false;
        
        int row = (i/3)*3, col = (j/3)*3;
        
        for(int k = row;k < row+3;k++){
            for(int m = col; m < col+3;m++){
                if(grid[k][m] == n) return false;
            }
        }
        
        return true;
    }
    
    bool find(int& i, int& j, int grid[N][N]){
        
        for(int k = 0;k < N;k++)
            for(int m = 0;m < N;m++){
                if(grid[k][m] == 0){
                    i = k;
                    j = m;
                    return true;
                }
            }
        
        return false;
    }
    
    bool SolveSudoku(int grid[N][N])  
    { 
        // Your code here
        
        int i, j;
        if(!find(i,j,grid)) return true;
        
        for(int k = 1;k <= 9;k++){
            if(safe(i,j,k,grid)){
                grid[i][j] = k;
                if(SolveSudoku(grid)) return true;
                grid[i][j] = 0;
            }
        }
        
        return false;
    }
    
    //Function to print grids of the Sudoku.
    void printGrid(int grid[N][N]) 
    {
        // Your code here 
        for(int i = 0;i < N;i++){
            for(int j = 0;j < N;j++) cout << grid[i][j] << " ";
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