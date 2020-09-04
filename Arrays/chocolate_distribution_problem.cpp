#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin>>t;
    while(t--){
        
        ll n; cin >> n;
        ll ar[n];
        
        for(int i = 0;i < n;i++) cin >> ar[i];
        
        ll m; cin >> m;
        
        sort(ar,ar+n);
        
        ll mn = 99999999999;
        
        for(int j = m-1,i=0;j < n;i++,j++){
            mn = min(mn, ar[j]-ar[i]);
        }
        
        cout << mn << endl;
    }

	return 0;
}