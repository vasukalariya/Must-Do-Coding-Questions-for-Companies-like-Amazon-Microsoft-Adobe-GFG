// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution
{
    public:
    //Function to return the minimum cost to react at bottom
	//right cell from top left cell.
	
	
	int dx[4] = {1,0,-1,0};
	int dy[4] = {0,1,0,-1};
	
    int minimumCostPath(vector<vector<int>>& grid) 
    {
        // Code here
        int dist[600][600];
        
        memset(dist,999999,sizeof(dist));
        
        priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>> pq;
        
        dist[0][0] = grid[0][0];
        int n = grid.size();
        pq.push({dist[0][0],{0,0}});
        
        while(!pq.empty()){
            auto p = pq.top();
            pq.pop();
            
            int x = p.second.first;
            int y = p.second.second;
            
            for(int k = 0;k < 4;k++){
                int nx = x + dx[k];
                int ny = y + dy[k];
                
                if(nx >= 0 && ny >= 0 && nx < n && ny < n && dist[nx][ny] > dist[x][y] + grid[nx][ny]){
                    dist[nx][ny] = dist[x][y] + grid[nx][ny];
                    pq.push({dist[nx][ny],{nx,ny}});
                }
            }
        }
        
        return dist[n-1][n-1];
    }
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>>grid(n, vector<int>(n, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		int ans = obj.minimumCostPath(grid);
		cout << ans << "\n";
	}
	return 0;
}  // } Driver Code Ends