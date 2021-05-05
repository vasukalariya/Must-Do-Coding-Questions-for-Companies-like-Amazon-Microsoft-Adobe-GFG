// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends



class Solution
{
	public:
	//Function to return list containing vertices in Topological order. 
	
	bool vis[101010];
	
	void dfs(int idx, vector<int> adj[], vector<int> &order){
	    
	    vis[idx] = true;
	    
	    for(int i = 0;i < adj[idx].size();i++){
	        if(!vis[adj[idx][i]]) dfs(adj[idx][i],adj,order);
	    }
	    order.push_back(idx);
	}
	
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    // code here
	    memset(vis,false,sizeof(vis));
	    vector<int> order;
	    
	    
	    for(int i = 0;i < V;i++){
	        if(!vis[i]) dfs(i,adj,order);
	    }
	    
	    reverse(order.begin(), order.end());
	    return order;
	}
};

// { Driver Code Starts.

/*  Function to check if elements returned by user
*   contains the elements in topological sorted form
*   V: number of vertices
*   *res: array containing elements in topological sorted form
*   adj[]: graph input
*/
int check(int V, vector <int> &res, vector<int> adj[]) {
    vector<int> map(V, -1);
    for (int i = 0; i < V; i++) {
        map[res[i]] = i;
    }
    for (int i = 0; i < V; i++) {
        for (int v : adj[i]) {
            if (map[i] > map[v]) return 0;
        }
    }
    return 1;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N, E;
        cin >> E >> N;
        int u, v;

        vector<int> adj[N];

        for (int i = 0; i < E; i++) {
            cin >> u >> v;
            adj[u].push_back(v);
        }
        
        Solution obj;
        vector <int> res = obj.topoSort(N, adj);

        cout << check(N, res, adj) << endl;
    }
    
    return 0;
}  // } Driver Code Ends