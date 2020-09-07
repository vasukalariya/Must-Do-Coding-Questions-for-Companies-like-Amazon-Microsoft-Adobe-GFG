#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair

using namespace std;

string fs;

void rem(string s){
    string st;
    
    for(int i = 0;i < s.length();i++){
        if(i == 0 && s[i] != s[i+1]) st += s[i];
        else if(i == s.length()-1 && s[i] != s[i-1]) st += s[i];
        else{
            if(s[i] != s[i-1] && s[i] != s[i+1]) st += s[i];
        }
    }
    
    if(!s.compare(st)){ fs = st; return;}
    else rem(st);

}


int main()
{
    int t; cin>>t;
    while(t--){
        string st;
        fs = "";
        string s; cin >> s;
        rem(s);
        cout << fs << endl;
    }

    return 0;
}