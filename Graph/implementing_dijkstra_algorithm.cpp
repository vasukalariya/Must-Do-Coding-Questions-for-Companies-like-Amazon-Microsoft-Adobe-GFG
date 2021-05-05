// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends



class Solution
{
	public:
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        // Code here
        
        vector<int> dist(V,INT_MAX);
        dist[S] = 0;
        bool vis[V] = {false};
        
        for(int i = 0;i < V;i++){
            int mn = INT_MAX;
            int mn_node = 0;
            for(int j = 0;j < V;j++){
                if(!vis[j] && dist[j] < mn){
                    mn = dist[j];
                    mn_node = j;
                }
            }
            vis[mn_node] = true;
            for(int k = 0;k < adj[mn_node].size();k++){
                int dest = adj[mn_node][k][0];
                int dis = adj[mn_node][k][1];
                if(!vis[dest] && dist[mn_node] + dis < dist[dest]){
                    dist[dest] = dist[mn_node] + dis;
                }
            }
        }
        
        return dist;
    }
};


// { Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        int S;
        cin>>S;
        
        Solution obj;
    	vector<int> res = obj.dijkstra(V, adj, S);
    	
    	for(int i=0; i<V; i++)
    	    cout<<res[i]<<" ";
    	cout<<endl;
    }

    return 0;
}

  // } Driver Code Ends