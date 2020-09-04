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
        int cnt = -1;
        
        for(int i = 0;i < s.length();i++){
            if(s[i] == '1') cnt = i;
        }
        
        cout << cnt << endl;
    }

	return 0;
}