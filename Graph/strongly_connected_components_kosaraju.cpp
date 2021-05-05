// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends



class Solution
{
	public:
	//Function to find number of strongly connected components in the graph.
	
	bool vis[101010];
	
	void dfs(int idx, vector<int> adj[], stack<int> &order){
	    
	    vis[idx] = true;
	    for(int i = 0;i < adj[idx].size();i++){
	        if(!vis[adj[idx][i]]) dfs(adj[idx][i],adj,order);
	    }
	    order.push(idx);
	}
	
	void dfs2(int idx, vector<int> adj[]){
	    vis[idx] = true;
	    for(int i = 0;i < adj[idx].size();i++){
	        if(!vis[adj[idx][i]]) dfs2(adj[idx][i],adj);
	    }
	}
	
    int kosaraju(int V, vector<int> adj[])
    {
        //code here
        memset(vis,false,sizeof(vis));
        vector<int> revadj[V];
        stack<int> order;
        
        for(int i = 0;i < V;i++){
            for(int j = 0;j < adj[i].size();j++){
                revadj[adj[i][j]].push_back(i);
            }
        }
        
        for(int i = 0;i < V;i++){
            if(!vis[i]) dfs(i,adj,order);
        }
        
        memset(vis,false,sizeof(vis));
        
        int cnt = 0;
        
        while(!order.empty()){
            int idx = order.top();
            order.pop();
            if(!vis[idx]){
                cnt++;
                dfs2(idx,revadj);
            }
        }
        
        return cnt;
    }
};

// { Driver Code Starts.


int main()
{
    
    int t;
    cin >> t;
    while(t--)
    {
    	int V, E;
    	cin >> V >> E;

    	vector<int> adj[V];

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    	}

    	Solution obj;
    	cout << obj.kosaraju(V, adj) << "\n";
    }

    return 0;
}

  // } Driver Code Ends