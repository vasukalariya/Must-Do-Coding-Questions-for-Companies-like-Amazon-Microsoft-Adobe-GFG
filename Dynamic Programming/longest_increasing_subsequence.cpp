// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends



class Solution
{
    public:
    //Function to find length of longest increasing subsequence.
    int longestSubsequence(int n, int a[])
    {
       // your code here
       vector<int> seq;
       seq.push_back(a[0]);
       
       for(int i = 1;i < n;i++){
           if(a[i] > seq.back()) seq.push_back(a[i]);
           else{
               int idx = lower_bound(seq.begin(), seq.end(), a[i]) - seq.begin();
               seq[idx] = a[i];
           }
       }
       return seq.size();
    }
};

// { Driver Code Starts.
int main()
{
    //taking total testcases
    int t,n;
    cin>>t;
    while(t--)
    {
        //taking size of array
        cin>>n;
        int a[n];
        
        //inserting elements to the array
        for(int i=0;i<n;i++)
            cin>>a[i];
        Solution ob;
        //calling method longestSubsequence()
        cout << ob.longestSubsequence(n, a) << endl;
    }
}
  // } Driver Code Ends