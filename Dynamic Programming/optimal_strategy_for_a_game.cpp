// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends



//Function to find the maximum possible amount of money we can win.

long long dp[1010][1010];

long long choose(int i, int j, int arr[]){
    
    if(i == j) return 0;
    if(dp[i][j] != -1) return dp[i][j];
    
    if((i+j)%2) return dp[i][j] = max(arr[i] + choose(i+1,j,arr), arr[j] + choose(i,j-1,arr));
    else return dp[i][j] = min(choose(i+1,j,arr), choose(i,j-1,arr));
    
}


long long maximumAmount(int arr[], int n) 
{
    // Your code here
    memset(dp,-1,sizeof(dp));
    return choose(0,n-1,arr);
}

// { Driver Code Starts.

int main() {
    
    //taking total testcases
	int T;
	cin>>T;
	while(T--)
	{
	    //taking number of elements
	    int N;
	    cin>>N;
	    
	    int A[N];
	    
	    //inserting the elements
	    for(int i=0;i<N;i++)
	    cin>>A[i];
	    
	    //calling function maximumAmount()
	    cout<<maximumAmount(A,N)<<endl;
	    
	}
	return 0;
}  // } Driver Code Ends