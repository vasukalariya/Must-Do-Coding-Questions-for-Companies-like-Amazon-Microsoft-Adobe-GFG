#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair

using namespace std;

int main()
{
    int t; cin>>t;
    while(t--){
        
        int m, n; cin >> m >> n;
        int mat[m][n];
        
        for(int i = 0;i < m;i++) for(int j = 0;j < n;j++) cin >> mat[i][j];
        
        bool move = true;
        
        int i = 0,j = 0;
        char c = 'r';
        while(move){
            move = false;
            cout << mat[i][j] << " ";
            mat[i][j] = -1;
            if(mat[i][j+1] != -1 && j+1 < n && c == 'r'){
                j++;
                move = true;
                if(mat[i][j+1] == -1 || j == n-1) c = 'd';
                continue;
            }
            else if(mat[i+1][j] != -1 && i+1 < m && c == 'd'){
                i++;
                if(mat[i+1][j] == -1 || i == m-1) c = 'l';
                move = true;
                continue;
            }
            else if(mat[i][j-1] != -1 && j > 0 && c == 'l'){
                j--;
                if(mat[i][j-1] == -1 || j == 0) c = 'u';
                move = true;
                continue;
            }
            else if(mat[i-1][j] != -1 && i > 0 && c == 'u'){
                i--;
                if(mat[i-1][j] == -1 || i == 0) c = 'r';
                move = true;
                continue;
            }
        }
        
        cout << endl;
        
    }

	return 0;
}