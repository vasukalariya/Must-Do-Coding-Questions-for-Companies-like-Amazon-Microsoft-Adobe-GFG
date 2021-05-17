// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends



class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        // code here
        
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        bool vis[V] = {false};
        int val[V];
        memset(val,9999999,sizeof(val));
        val[0] = 0;
        pq.push({val[0],0});
        int cost = 0;
        
        while(!pq.empty()){
            int value = pq.top().first;
            int idx = pq.top().second;
            pq.pop();
            if(!vis[idx]){
                vis[idx] = true;
                cost += value;
                for(int i = 0;i < adj[idx].size();i++){
                    if(!vis[adj[idx][i][0]] && adj[idx][i][1] < val[adj[idx][i][0]]){
                        pq.push({adj[idx][i][1],adj[idx][i][0]});
                    }
                }
            }
        }
        
        return cost;
        
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
        
        Solution obj;
    	cout << obj.spanningTree(V, adj) << "\n";
    }

    return 0;
}

  // } Driver Code Ends