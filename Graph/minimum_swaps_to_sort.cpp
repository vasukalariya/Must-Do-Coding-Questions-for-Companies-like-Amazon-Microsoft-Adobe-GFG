// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends



class Solution 
{
    public:
    //Function to find the minimum number of swaps required to sort the array. 
	int minSwaps(vector<int>&nums)
	{
	    // Code here
	    
	    int total = 0;
	    vector<pair<int,int>> vec;
	    
	    for(int i = 0;i < nums.size();i++){
	        vec.push_back({nums[i],i});
	    }
	    
	    sort(vec.begin(), vec.end());
	    
	    bool vis[nums.size()] = {false};
	    
	    for(int i = 0;i < nums.size();i++){
	        
	        if(vis[i] == true) continue;
	        
	        vis[i] = true;
	        int cnt = 0;
	        int next = vec[i].second;
	        while(!vis[next]){
	            vis[next] = true;
	            cnt++;
	            next = vec[next].second;
	        }
	        
	        total += cnt;
	    }
	    
	    return total;
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<int>nums(n);
		for(int i = 0; i < n; i++)
			cin >> nums[i];
		Solution obj;
		int ans = obj.minSwaps(nums);
		cout << ans <<"\n";
	}
	return 0;
}  // } Driver Code Ends