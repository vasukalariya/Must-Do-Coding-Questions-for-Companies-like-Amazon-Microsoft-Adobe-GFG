// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution 
{
    public:
	//Function to return a list containing the DFS traversal of the graph.
	
	bool vis[10010];
	
	void dfs(int idx, vector<int> adj[], int V, vector<int> &visited){
	    vis[idx] = true;
	    visited.push_back(idx);
	    for(int i = 0;i < adj[idx].size();i++){
	        if(!vis[adj[idx][i]]){
	            dfs(adj[idx][i],adj,V,visited);
	        }
	    }
	}
	
	
	vector<int>dfsOfGraph(int V, vector<int> adj[])
	{
	    // Code here
	    memset(vis,false,sizeof(vis));
	    vector<int> visited;
	    
	    for(int i = 0;i < V;i++){
	        if(!vis[i]){
	            dfs(i,adj,V,visited);
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
    		adj[v].push_back(u);
    	}
        // string s1;
        // cin>>s1;
        Solution obj;
        vector<int>ans=obj.dfsOfGraph(V, adj);
        for(int i=0;i<ans.size();i++){
        	cout<<ans[i]<<" ";
        }
        cout<<endl;
	}
	return 0;
}  // } Driver Code Ends