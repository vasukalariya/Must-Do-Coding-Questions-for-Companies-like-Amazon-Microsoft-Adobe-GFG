#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair

using namespace std;

int m,n;

int countpaths(int i, int j){
    
    if(i == m-1 && j == n-1) return 1;
    else if(i >= m || j >= n) return 0;
    
    return countpaths(i+1,j) + countpaths(i,j+1);
}


int main()
{
    int t; cin>>t;
    while(t--){
        
        cin >> m >> n;
        
        cout << countpaths(0,0) << endl;
    }

	return 0;
}