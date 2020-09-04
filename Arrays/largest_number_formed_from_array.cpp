#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair

using namespace std;

bool sorts(string a, string b){
    return a+b > b+a;
}

int main()
{
    int t; cin>>t;
    while(t--){
        
        int n; cin >> n;
        string s[n];
        
        for(int i = 0;i < n;i++) cin >> s[i];
        
        sort(s, s+n, sorts);
        
        for(int i = 0;i < n;i++) cout << s[i];
        cout << endl;
    }

	return 0;
}