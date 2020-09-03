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
        
        ll mx = ar[n-1]+1;
        ll mxi = n-1;
        ll mni = 0;
        
        for(int i = 0;i < n;i++){
            if(i%2 == 0){
                ar[i] += (ar[mxi]%mx)*mx;
                mxi--;
            }
            else{
                ar[i] += (ar[mni]%mx)*mx;
                mni++;
            }
        }
        
        for(int i = 0;i < n;i++){
            ar[i] = ar[i]/mx;
            cout << ar[i] << " ";
        }
        cout<<endl;
        
    }

	return 0;
}