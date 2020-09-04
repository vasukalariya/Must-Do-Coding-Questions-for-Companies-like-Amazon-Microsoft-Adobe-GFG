#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
    int t; cin>>t;
    while(t--){
        
        ll n, k; cin >> n >> k;
        
        ll ar[n];
        ll dum[k];
        
        for(int i = 0;i < n;i++) cin >> ar[i];
        
        for(int i = 0;i < n;i+=k){
            ll cnt = 0;
            for(int j = i;j < i+k && j < n;j++){
                cnt++;
                dum[j-i] = ar[j];
            }
            for(int j = 0;j < cnt;j++){
                ar[i+j] = dum[cnt-j-1];
            }
        }
        
        for(int i = 0;i < n;i++) cout << ar[i] << " ";
        cout << endl;
    }

    return 0;
}