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
        
        sort(br, br + y);
        
        ll ex[5] = {0};
        for(int i = 0;i < y;i++){
            if(br[i] < 5){
                ex[br[i]]++;
            }
        }
        
        ll total = 0;
        
        for(int i = 0;i < x;i++){
            
            if(ar[i] == 1) continue;
            int mn = upper_bound(br,br+y,ar[i]) - br;
            total += (y-mn);
            
            total += ex[1];
            if(ar[i] == 2) total -= (ex[3]+ex[4]);
            if(ar[i] == 3) total += ex[2];
        }
        
        cout << total << endl;
    }

	return 0;
}