#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair

using namespace std;

int main()
{
    int t; cin>>t;
    while(t--){
        
        int n; cin >> n;
        int ar[n];
        int sar[n];
        
        for(int i = 0;i < n;i++){ cin >> ar[i]; sar[i] = ar[i];}
        
        sort(sar, sar+n);
        
        int ind = -1;
        bool cond = false;
        int mx = ar[0];
        
        for(int i = 1;i < n;i++){
            if(sar[i] == ar[i] && !cond && ar[i] >= mx && i != n-1){
                ind = ar[i];
                cond = true;
            }
            if(cond && ind > ar[i]){
                cond = false;
                ind = -1;
            }
            if(!cond) mx = max(mx, ar[i]);
        }
        
        cout << ind << endl;
    }

	return 0;
}