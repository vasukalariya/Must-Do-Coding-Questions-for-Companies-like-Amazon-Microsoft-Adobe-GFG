// { Driver Code Starts
#include<bits/stdc++.h>

using namespace std;

 // } Driver Code Ends
class Solution{
    public:
    /*The function takes an array of heights, width and 
    length as its 3 arguments where each index i value 
    determines the height, width, length of the ith box. 
    Here n is the total no of boxes.*/
    
    static bool comp(pair<int,pair<int,int>> a, pair<int,pair<int,int>> b){
        return a.second.first*a.second.second > b.second.first*b.second.second;
    }
    
    int maxHeight(int height[],int width[],int length[],int n)
    {
        //Your code here
        
        vector<pair<int,pair<int,int>>> vec;
        
        for(int i = 0;i < n;i++){
            int mb = min(width[i], length[i]);
            int ml = max(width[i], length[i]);
            vec.push_back({height[i],{ml,mb}});

            mb = min(width[i], height[i]);
            ml = max(width[i], height[i]);
            vec.push_back({length[i],{ml,mb}});

            mb = min(height[i], length[i]);
            ml = max(height[i], length[i]);
            vec.push_back({width[i],{ml,mb}});
        }
        
        sort(vec.begin(), vec.end(), comp);
        
        int val[vec.size()];
        
        for(int i = 0;i < vec.size();i++) val[i] = vec[i].first;
        
        int mx = 0;
        
        for(int i = 0;i < vec.size();i++){
            for(int j = 0;j < i;j++){
                if(vec[j].second.first > vec[i].second.first && vec[j].second.second > vec[i].second.second) val[i] = max(val[i], val[j] + vec[i].first);
            
            }
            mx = max(mx,val[i]);
        }
        
        return mx;
    }
};

// { Driver Code Starts.

int main() {
	int t;
	cin>>t;
	while(t--)
	{
        int n;
        cin>>n;
        
    
        int A[105],B[105],C[105];
        for(int i = 0; i < n; i++)cin >> A[i];
        for(int j = 0; j < n; j++)cin >> B[j];
        for(int k = 0; k < n; k++)cin >> C[k];
        Solution ob;
        cout<<ob.maxHeight(A,B,C,n)<<endl;
    }
	
	return 0;
}
	  // } Driver Code Ends