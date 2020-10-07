// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


int josephus(int n, int k);

int main() {
	
	int t;
	cin>>t;//testcases
	while(t--)
	{
		int n,k;
		cin>>n>>k;//taking input n and k
		
		//calling josephus() function
		cout<<josephus(n,k)<<endl;
	}
	return 0;
}// } Driver Code Ends


/*You are required to complete this method */

int winner(int n, int k){
    
    if(n == 1) return 0;
    return (winner(n-1,k)+k)%n;
}


int josephus(int n, int k)
{
   //Your code here
   return winner(n,k) + 1;
}
