#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int t; cin>>t;
    while(t--){
        
        ll n,k; cin >> n;
        ll ar[n];
        
        for(int i = 0;i < n;i++) cin >> ar[i];
        
        sort(ar, ar+n);
        
        cin >> k;
        
        cout << ar[k-1] << endl;
        
    }

	return 0;
}