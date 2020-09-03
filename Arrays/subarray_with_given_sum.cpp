#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
    int t; cin>>t;
    while(t--){
        
        ll n, s; cin >> n >> s;
        ll ar[n];
        for(int i = 0;i < n;i++) cin >> ar[i];
        bool cond = false;
        
        for(int i = 0;i < n;i++){
            ll sum = 0;
            ll ind = -1;
            for(int j = i;j < n;j++){
                sum += ar[j];
                if(sum >= s){ind = j; break;}
            }
            if(sum == s){
                cout << i+1 << " " << ind+1 << endl;
                cond = true;
                break;
            }
        }
        if(!cond) cout << -1 << endl;
    }

	return 0;
}