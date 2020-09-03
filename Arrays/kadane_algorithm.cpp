#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
    int t; cin>>t;
    while(t--){
        
        int n; cin>>n;
        ll ar[n];
        for(int i = 0;i < n;i++) cin>>ar[i];
        
        ll sum = ar[0];
        ll mx = ar[0];
        for(int i = 1;i < n;i++){
            sum = max(ar[i], sum+ar[i]);
            mx = max(mx, sum);
        }
        cout<<mx<<endl;
    }

	return 0;
}