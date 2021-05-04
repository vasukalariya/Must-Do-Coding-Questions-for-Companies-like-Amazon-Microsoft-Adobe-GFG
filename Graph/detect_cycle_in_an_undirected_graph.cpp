// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends



class Solution 
{
    public:
    //Function to detect cycle in an undirected graph.
    
    bool vis[101010];
    
    void dfs(int idx, int parent, vector<int> adj[], bool &check){
        
        if(check == true) return;
        vis[idx] = true;
        for(int i = 0;i < adj[idx].size();i++){
            if(vis[adj[idx][i]] == true && adj[idx][i] != parent){
                check = true;
                return;
            }
            if(!vis[adj[idx][i]]) dfs(adj[idx][i],idx,adj,check);
        }
        
    }
    
    
	bool isCycle(int V, vector<int>adj[])
	{
	    // Code here
	    memset(vis,false,sizeof(vis));
	    bool check = false;
	    
	    for(int i = 0;i < V;i++){
	        if(!vis[i]){
	            dfs(i,-1,adj,check);
	        }
	    }
	    return check;
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		Solution obj;
		bool ans = obj.isCycle(V, adj);
		if(ans)
			cout << "1\n";
		else cout << "0\n";
	}
	return 0;
}  // } Driver Code Ends