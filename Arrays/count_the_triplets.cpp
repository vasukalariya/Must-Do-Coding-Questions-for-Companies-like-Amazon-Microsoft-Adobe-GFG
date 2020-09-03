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
        ll cnt = 0;
        
        sort(ar, ar + n);
        
        for(int i = n-1;i >= 2;i--){
            int l = 0, r = i-1;
            while(l < r){
                if(ar[l] + ar[r] == ar[i]){
                    l++;
                    r--;
                    cnt++;
                }
                else if(ar[l] + ar[r] > ar[i]) r--;
                else l++;
            }
        }
        
        
        if(cnt) cout << cnt << endl;
        else cout << -1 << endl;
        
    }

	return 0;
}