#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair

using namespace std;

int n,m,k;
int mat[101][101];

void dfs(int i, int j, int replace){
    
    if(i < 0 || j < 0 || i >= n || j >= m || mat[i][j] != replace) return;
    
    mat[i][j] = k;
    
    dfs(i+1,j,replace);
    dfs(i,j+1,replace);
    dfs(i-1,j,replace);
    dfs(i,j-1,replace);
    
}



int main()
{
    int t; cin>>t;
    while(t--){
        int x,y;
        
        cin >> n >> m;
        for(int i = 0;i < n;i++) for(int j = 0;j < m;j++) cin >> mat[i][j];
        
        cin >> x >> y >> k;
        
        dfs(x,y,mat[x][y]);
        
        for(int i = 0;i < n;i++) for(int j = 0;j < m;j++) cout << mat[i][j] << " ";
        
        cout << endl;
    }

	return 0;
}