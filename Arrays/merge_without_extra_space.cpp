#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
    int t; cin>>t;
    while(t--){
        
        ll x,y; cin >> x >> y;
        ll ar[x];
        ll br[y];
        
        for(int i = 0;i < x;i++) cin >> ar[i];
        for(int i = 0;i < y;i++) cin >> br[i];
        
        ll cnt = min(x,y);
        ll f = x-1, s = 0;
        
        while(cnt){
            if(ar[f] >= br[s]){
                swap(ar[f], br[s]);
                f--;
                s++;
            }
            else{
                break;
            }
            cnt--;
        }
        
        sort(ar, ar + x);
        sort(br, br + y);
        
        for(int i = 0;i < x;i++) cout << ar[i] << " ";
        for(int j = 0;j < y;j++) cout << br[j] << " ";
        
        cout << endl;
    }
	return 0;
}