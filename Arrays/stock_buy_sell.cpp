#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair

using namespace std;

int main()
{
    int t; cin>>t;
    while(t--){
        int n;
        cin >> n;
        int ar[n];
        
        for(int i = 0;i < n;i++) cin >> ar[i];
        int pr = 0;
        int i = 0;
        
        vector<pair<int,int>> vec;
        
        while(i < n-1){
            
            while(i < n-1 && ar[i+1] <= ar[i]) i++;
            
            if(i == n-1) break;
            
            int b = i++;
            
            while(i < n && ar[i] >= ar[i-1]) i++;
            
            int s = i-1;
            
            pr += (ar[s]-ar[b]);
            
            if(b != s) vec.pb(mp(b,s));
        }
        
        if(pr == 0){
            cout << "No Profit" << endl;
            continue;
        }
        
        for(int i = 0;i < vec.size();i++) cout << "(" << vec[i].first << " " << vec[i].second << ") ";
        cout << endl;
        
        
    }

	return 0;
}