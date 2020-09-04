#include<bits/stdc++.h>

using namespace std;

int main()
{
    int t; cin>>t;
    while(t--){
        
        int n; cin >> n;
        int ar[n];
        for(int i = 0;i < n;i++) cin >> ar[i];
        
        bool leader[n] = {false};
        leader[n-1] = true;
        
        int mx = ar[n-1];
        
        for(int i = n-2;i >= 0;i--){
            if(ar[i] >= mx){
                leader[i] = true;
            }
            mx = max(mx, ar[i]);
        }
        
        for(int i = 0;i < n;i++){
            if(leader[i]) cout << ar[i] << " ";
        }
        cout << endl;
        
    }

	return 0;
}