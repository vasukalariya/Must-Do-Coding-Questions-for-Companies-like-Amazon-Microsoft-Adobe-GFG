#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair

using namespace std;

int main()
{
    int t; cin>>t;
    while(t--){
        
        int fi[26] = {0};
        int se[26] = {0};
        
        string s,t; cin >> s >> t;
        
        for(int i = 0;i < s.length();i++){
            fi[s[i]-'a']++;
        }
        for(int i = 0;i < t.length();i++){
            se[t[i]-'a']++;
        }
        
        bool match = true;
        for(int i = 0;i < 26;i++){
            if(fi[i] != se[i]){
                match = false;
                break;
            }
        }
        if(match) cout << "YES" << endl;
        else cout << "NO" << endl;
    }

	return 0;
}