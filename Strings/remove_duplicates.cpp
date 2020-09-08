#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair

using namespace std;

int main()
{
    int t; cin>>t;
    cin.ignore();
    while(t--){
        string s;
        getline(cin,s);
        int cnt[256] = {0};
        string st;
        for(int i = 0;i < s.length();i++){
            if(cnt[s[i]] == 0){
                st += s[i];
                cnt[s[i]]++;
            }
        }
        cout << st << endl;
    }

	return 0;
}