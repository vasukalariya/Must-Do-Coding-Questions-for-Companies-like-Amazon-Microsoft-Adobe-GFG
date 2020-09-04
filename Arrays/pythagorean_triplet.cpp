#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair

using namespace std;

int main()
{
    int t; cin>>t;
    while(t--){
        
        ll n; cin >> n;
        ll ar[n];
        
        bool avail[1001] = {false};
        
        for(int i = 0;i < n;i++){
            cin >> ar[i];
            avail[ar[i]] = true;
        }
        
        bool pt = false;
        
        for(int i = 1;i < 1001;i++){
            for(int j = 1;j < 1001;j++){
                if(i == j) continue;
                else if(!(avail[i] && avail[j])) continue;
                
                double num = i*i + j*j;
                double rnum = sqrt(num);
                if(floor(rnum) != rnum) continue;
                if(avail[(int)rnum]){
                    pt = true;
                    break;
                }
            }
            if(pt) break;
        }
        
        if(pt) cout << "Yes" << "\n";
        else cout << "No" << "\n";
    }

	return 0;
}