#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair

using namespace std;

int main()
{
    int t; cin>>t;
    while(t--){
        
        string s, t; cin >> s >> t;
        if(s.length() < 3) cout << 1 << endl;
        else{
            string anti, clo;
            for(int i = 0;i < s.length();i++) anti += s[(i+2)%(s.length())];
            
            for(int i = 0;i < s.length();i++) clo += s[(i-2 + s.length())%(s.length())];
            
            if(anti == t || clo == t) cout << 1 << endl;
            else cout << 0 << endl;
        }
    }

	return 0;
}