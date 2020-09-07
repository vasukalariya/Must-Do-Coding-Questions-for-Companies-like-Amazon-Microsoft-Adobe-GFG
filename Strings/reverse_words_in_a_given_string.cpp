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
        int i = s.length()-1;
        string st;
        string dum;
        
        while(i >= 0){
            if(s[i] != '.'){
                dum += s[i];
            }
            else{
                reverse(dum.begin(), dum.end());
                st += dum;
                st += '.';
                dum = "";
            }
            i--;
        }
        reverse(dum.begin(),dum.end());
        st += dum;
        
        cout << st << endl;
    }

	return 0;
}