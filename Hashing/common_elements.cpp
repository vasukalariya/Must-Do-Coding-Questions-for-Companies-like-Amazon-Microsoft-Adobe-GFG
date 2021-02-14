// { Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


//User function Template for C++

//Back-end complete function Template for C++


vector<int> common_element(vector<int>v1,vector<int>v2)
{
    // Your code here
    map<int,int> mp;
    vector<int> v;
    
    for(int i = 0;i < v1.size();i++){
        mp[v1[i]]++;
    }
    
    for(int i = 0;i < v2.size();i++){
        if(mp[v2[i]]){
            v.push_back(v2[i]);
            mp[v2[i]]--;
        }
    }
    
    
    sort(v.begin(),v.end());
    
    return v;
}

// { Driver Code Starts.


int main(){
    int t;
    cin>>t;
    while(t--){
        
        int n;
        cin>>n;
        vector<int>v1(n,0);
        for(int i=0;i<n;i++)
        {
            cin>>v1[i];
        }
        int m;
        cin>>m;
        vector<int>v2(m,0);
        for(int i=0;i<m;i++)
        {
            cin>>v2[i];
        }
        vector<int>result;
        result=common_element(v1,v2);
        for(auto i:result)
        {
            cout<<i<<" ";
        }
        cout<<endl;
        
    }
}  // } Driver Code Ends