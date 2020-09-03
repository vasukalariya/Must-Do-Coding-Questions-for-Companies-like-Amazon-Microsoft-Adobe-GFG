#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
    int t; cin>>t;
    while(t--){
        ll n; cin >> n;
        ll ar[n-1] = {0};
        
        for(int i = 0;i < n-1;i++) cin >> ar[i];
        
        sort(ar, ar + n-1);
        
        if(n == 1 || ar[0] != 1) cout << 1 << endl;
        else{
            bool cond = false;
            for(int i = 0;i < n-2;i++){
                if(ar[i+1] - ar[i] == 2){
                    cout << ar[i]+1 << endl;
                    cond = true;
                    break;
                }
            }
            if(!cond) cout << ar[n-2] + 1 << endl;
        }
        
    }

	return 0;
}