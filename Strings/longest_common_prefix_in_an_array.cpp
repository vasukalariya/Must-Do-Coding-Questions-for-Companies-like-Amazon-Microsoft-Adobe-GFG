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
        string s[n];
        
        int mn = 9999;
        for(int i = 0;i < n;i++){
            cin >> s[i];
            int sz = s[i].length();
            mn = min(mn,sz);
        }
        
        string pref;
        bool br = false;
        for(int i = 0;i < mn;i++){
            char c = s[0][i];
            for(int j = 1;j < n;j++){
                if(s[j][i] != c){
                    br = true;
                    break;
                }
            }
            if(br) break;
            else{
                pref += c;
            }
        }
        
        if(pref.length() == 0) cout << -1 << endl;
        else cout << pref << endl;
        
    }

	return 0;
}