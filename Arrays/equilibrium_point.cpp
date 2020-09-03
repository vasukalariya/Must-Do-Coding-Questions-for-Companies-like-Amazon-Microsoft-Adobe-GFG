#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
    int t; cin>>t;
    while(t--){
        ll n; cin >> n;
        ll ar[n];
        for(int i = 0;i < n;i++) cin >> ar[i];
        
        if(n == 1){
            cout << 1 << endl;
            continue;
        }
        
        ll start[n+1];
        ll end[n+1];
        
        start[0] = 0;
        end[n] = 0;
        
        for(int i = 1;i <= n;i++) start[i] = ar[i-1] + start[i-1];
        for(int i = n-1;i >= 0;i--) end[i] = ar[i] + end[i+1];
        
        bool cond = false;
        
        for(int i = 1;i <= n;i++){
            if(start[i-1] == end[i]){
                cout << i << endl;
                cond = true;
                break;
            }
        }
        
        if(!cond) cout << -1 << endl;
    }

	return 0;
}