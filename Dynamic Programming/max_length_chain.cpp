// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct val{
	int first;
	int second;
};



int maxChainLen(struct val p[],int n);
int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		val p[n];
		for(int i=0;i<n;i++)
		{
			cin>>p[i].first>>p[i].second;
		}
		
		cout<<maxChainLen(p,n)<<endl;
	}
	return 0;
}// } Driver Code Ends


/*
The structure to use is as follows
struct val{
	int first;
	int second;
};*/

/*You are required to complete this method*/

bool comp(val a, val b){
    return a.second < b.second;
}

int maxChainLen(struct val p[],int n)
{
    //Your code here
    // Greedy Activity Selection solution can also be used as it is more efficient.
    sort(p,p+n,comp);
    
    int dp[n];
    for(int i = 0;i < n;i++) dp[i] = 1;
    
    for(int i = 1;i < n;i++){
        for(int j = 0;j < i;j++){
            if(p[j].second < p[i].first) dp[i] = max(dp[i], dp[j] + 1);
        }
    }
    
    int mx = 0;
    for(int i = 0;i < n;i++) mx = max(mx,dp[i]);
    
    return mx;
}