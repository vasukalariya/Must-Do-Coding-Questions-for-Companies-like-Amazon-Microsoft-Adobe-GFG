// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

int findLongestConseqSubseq(int arr[], int n);
 
// Driver program
int main()
{
 int  t,n,i,a[100001];
 cin>>t;
 while(t--)
 {
  cin>>n;
  for(i=0;i<n;i++)
  cin>>a[i];
  cout<<findLongestConseqSubseq(a, n)<<endl;
 }
      
    return 0;
}// } Driver Code Ends


// arr[] : the input array
// N : size of the array arr[]

// return the length of the longest subsequene of consecutive integers
int findLongestConseqSubseq(int arr[], int N)
{
  //Your code here
    bool avail[100005];
    memset(avail,false,sizeof(avail));
    
    for(int i = 0;i < N;i++) avail[arr[i]] = true;
    
    int cnt = 1;
    int mx = 1;
    
    for(int i = 0;i < 100005;i++){
        if(avail[i] && avail[i+1]) cnt++;
        else cnt = 1;
        mx = max(mx,cnt);
    }
    
    return mx;
}

