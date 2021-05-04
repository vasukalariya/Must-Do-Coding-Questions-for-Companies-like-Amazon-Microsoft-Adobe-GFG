// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends



class Solution
{
    public:
    //Function to return Breadth First Traversal of given graph.
	vector<int>bfsOfGraph(int V, vector<int> adj[])
	{
	    // Code here
	    queue<int> q;
	    bool vis[V];
	    memset(vis,false,sizeof(vis));
	    vector<int> visited;
	    
	    q.push(0);
	    vis[0] = true;
	    
	    while(!q.empty()){
	        int front = q.front();
	        visited.push_back(front);
	        q.pop();
	        
	        for(int i = 0;i < adj[front].size();i++){
	            if(!vis[adj[front][i]]){
	                vis[adj[front][i]] = true;
	                q.push(adj[front][i]);
	            }
	        }
	    }
	    
	    return visited;
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
    	cin >> V >> E;

    	vector<int> adj[V];

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    // 		adj[v].push_back(u);
    	}
        // string s1;
        // cin>>s1;
        Solution obj;
        vector<int>ans=obj.bfsOfGraph(V, adj);
        for(int i=0;i<ans.size();i++){
        	cout<<ans[i]<<" ";
        }
        cout<<endl;
	}
	return 0;
}  // } Driver Code Ends