// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h> 
using namespace std;



void sortA1ByA2(int a1[], int n, int a2[], int m);

// Driver program to test above function 
int main(int argc, char *argv[]) 
{ 
	
	int t;
	
	cin >> t;
	
	while(t--){
	    
	    int n, m;
	    cin >> n >> m;
	    
	    int a1[n];
	    int a2[m];
	    
	    for(int i = 0;i<n;i++){
	        cin >> a1[i];
	    }
	    
	    for(int i = 0;i<m;i++){
	        cin >> a2[i];
	    }
	    
	    sortA1ByA2(a1, n, a2, m); 
	
	   
	    for (int i = 0; i < n; i++) 
		    cout<<a1[i]<<" ";
		
	    cout << endl;
	    
	    
	}
	return 0; 
} 
// } Driver Code Ends


//User function template in C++

// A1[] : the input array-1
// N : size of the array A1[]
// A2[] : the input array-2
// M : size of the array A2[]
void sortA1ByA2(int A1[], int N, int A2[], int M) 
{
    //Your code here
    map<int,int> mp;
    
    for(int i = 0;i < N;i++){
        mp[A1[i]]++;
    }
    int k = 0;
    for(int i = 0;i < M;i++){
        if(mp[A2[i]]){
            for(int j = 0;j < mp[A2[i]];j++){
                A1[k++] = A2[i];
            }
            mp.erase(A2[i]);
        }
    }
    for(auto x:mp){
        for(int i = 0;i < x.second;i++) A1[k++] = x.first;
    }
} 