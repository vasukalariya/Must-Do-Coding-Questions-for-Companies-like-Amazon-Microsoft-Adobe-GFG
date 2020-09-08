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
        int mx = 0;
        
        for(int i = 0;i < s.length();i++){
            map<char,int> m;
            int cnt = 0;
            for(int j = i;j < s.length();j++){
                if(m[s[j]] == 0){
                    cnt++;
                    m[s[j]]++;
                }
                else break;
            }
            mx = max(mx, cnt);
        }
        cout << mx << endl;
    }

	return 0;
}