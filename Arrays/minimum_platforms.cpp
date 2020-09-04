#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
using namespace std;

int main()
{
    int t; cin>>t;
    while(t--){
        
        int n; cin >> n;
        int ar[n];
        int dt[n];
        
        for(int i = 0;i < n;i++) cin >> ar[i];
        for(int i = 0;i < n;i++) cin >> dt[i];
        
        sort(ar, ar+n);
        sort(dt, dt+n);
        
        int cnt = 1, mx = 1;
        int i = 1, j = 0;
        
        while(i < n && j < n){
            
            if(ar[i] <= dt[j]){
                cnt++;
                i++;
            }
            else{
                cnt--;
                j++;
            }
            mx = max(mx, cnt);
        }
        cout << mx << endl;
        
    }

	return 0;
}