#include<bits/stdc++.h>

using namespace std;

int main()
{
    int t; cin>>t;
    while(t--){
        
        int n; cin >> n;
        int ar[n];
        int cnt[3] = {0};
        
        for(int i = 0;i < n;i++){
            cin >> ar[i];
            cnt[ar[i]]++;
        }
        
        int st = 0;
        while(cnt[0]){
            ar[st++] = 0;
            cnt[0]--;
        }
        while(cnt[1]){
            ar[st++] = 1;
            cnt[1]--;
        }
        while(cnt[2]){
            ar[st++] = 2;
            cnt[2]--;
        }
        
        for(int i = 0;i < n;i++) cout << ar[i] << " ";
        
        cout << endl;
    }

	return 0;
}