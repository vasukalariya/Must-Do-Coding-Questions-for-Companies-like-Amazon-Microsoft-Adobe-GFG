#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair

using namespace std;

struct qnode{
    int x;
    int y;
    int t;
};

int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

int main()
{
    int t; cin>>t;
    while(t--){
        
        int r,c; cin >> r >> c;
        
        int mat[r][c];
        
        for(int i = 0;i < r;i++) for(int j = 0;j < c;j++) cin >> mat[i][j];
        
        bool vis[r][c];
        memset(vis, false, sizeof vis);
        
        queue<qnode> q;
        
        for(int i = 0;i < r;i++){
            for(int j = 0;j < c;j++){
                if(mat[i][j] == 2)
                {
                    qnode node;
                    node.x = i;
                    node.y = j;
                    node.t = 0;
                    q.push(node);
                }
            }
        }
        
        int tmax = 0;
        
        while(!q.empty()){
            qnode temp = q.front();
            vis[temp.x][temp.y] = true;
            q.pop();
            
            for(int i = 0;i < 4;i++){
                int newx = temp.x + dx[i];
                int newy = temp.y + dy[i];
                
                if(newx < 0 || newx >= r || newy < 0 || newy >= c || mat[newx][newy] == 0) continue;
                
                if(!vis[newx][newy]){
                    int d = temp.t;
                    qnode new_node;
                    new_node.x = newx;
                    new_node.y = newy;
                    new_node.t = d;
                    
                    if(mat[temp.x][temp.y] == 2 && mat[newx][newy] == 1){
                        new_node.t++;
                        mat[newx][newy] = 2;
                    }
                    
                    tmax = max(tmax, new_node.t);
                    q.push(new_node);
                }
            }
        }
        
        bool valid = true;
        
        for(int i = 0;i < r;i++){
            for(int j = 0;j < c;j++){
                if(mat[i][j] == 1){
                    valid = false;
                    break;
                }
            }
            if(!valid) break;
        }

        if(valid) cout << tmax << endl;
        else cout << -1 << endl;
        
    }

	return 0;
}