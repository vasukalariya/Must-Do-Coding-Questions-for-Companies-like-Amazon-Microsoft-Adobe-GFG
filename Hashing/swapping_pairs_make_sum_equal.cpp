// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution{

	public:
	int findSwapValues(int A[], int n, int B[], int m)
	{
        // Your code goes here
        int s1 = 0, s2 = 0;
        map<int,bool> mp;
        
        for(int i = 0;i < n;i++){
            s1 += A[i];
            mp[A[i]] = true;
        }
        
        for(int i = 0;i < m;i++){
            s2 += B[i];
        }
        
        bool pos = false;
        int diff;
        
        diff = abs(s2-s1);
        
        if(diff%2 != 0) return -1;
        
        for(int i = 0;i < m;i++){
            if(s2 >= s1 && mp[B[i]-diff]) return 1;
            else if(s1 > s2 && mp[diff-B[i]]) return 1;
        }
        
        return -1;
	}
 

};

// { Driver Code Starts.

int main() 
{
   	
   	int t;
    cin >> t;
    while (t--)
    {
    	int n,m;
        cin>>n>>m;
        int a[n];
        int b[m];
        for(int i=0;i<n;i++)
            cin>>a[i];
        for(int i=0;i<m;i++)
            cin>>b[i];
        

        Solution ob;
        cout <<  ob.findSwapValues(a, n, b, m);
	    cout << "\n";
	     
    }
    return 0;
}





  // } Driver Code Ends