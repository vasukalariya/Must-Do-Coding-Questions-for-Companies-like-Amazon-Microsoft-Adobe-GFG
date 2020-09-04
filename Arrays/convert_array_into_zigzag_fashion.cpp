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
        for(int i = 0;i < n;i++) cin >> ar[i];
        
        bool swp = true;
        for(int i = 0; i < n-1;i++){
            if(i%2 == 0){
                if(ar[i+1] < ar[i]){
                    swap(ar[i],ar[i+1]);
                    swp = true;
                }
            }
            else{
                if(ar[i] < ar[i+1]){
                    swap(ar[i],ar[i+1]);
                    swp = true;
                }
            }
        }
        
        for(int i = 0;i < n;i++) cout << ar[i] << " ";
        cout << endl;
    }

    return 0;
}