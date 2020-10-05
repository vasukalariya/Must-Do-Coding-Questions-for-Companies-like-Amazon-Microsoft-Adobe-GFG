#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair

using namespace std;

int main()
{
    int t; cin>>t;
    while(t--){
        
        string s; cin >> s;
        map<char,int> m;
        
        for(int i = 0;i < s.length();i++) m[s[i]]++;
        
        int mx = -1;
        for(auto x:m){
            if(x.second > mx) mx = x.second;
        }
        
        if(mx > (s.length()+1)/2) cout << 0 << endl;
        else cout << 1 << endl;
        
        
    }

	return 0;
}