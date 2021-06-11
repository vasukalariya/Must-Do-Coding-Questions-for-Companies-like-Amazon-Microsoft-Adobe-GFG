// { Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
class Solution
{
public:
    vector<int> candyStore(int candies[], int N, int K)
    {
        // Write Your Code here
        int c = ceil(N/(K+1.0));
        sort(candies,candies+N);
        
        int mn = 0, mx = 0;
        
        for(int i = 0;i < c;i++){
            mn += candies[i];
            mx += candies[N-1-i];
        }
        
        vector<int> ans;
        ans.push_back(mn);
        ans.push_back(mx);
        
        return ans;
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N, K;
        cin >> N >> K;
        int candies[N];

        for (int i = 0; i < N; i++)
        {
            cin >> candies[i];
        }

        Solution ob;
        vector<int> cost = ob.candyStore(candies, N, K);
        cout << cost[0] << " " << cost[1] << endl;
    }
    return 0;
}  // } Driver Code Ends