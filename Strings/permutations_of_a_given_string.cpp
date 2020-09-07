#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair

using namespace std;

void permute(string s, int i, int j){
    if(i == j) cout << s << " ";
    else{
        for(int k = i;k <= j;k++){
            swap(s[i],s[k]);
            permute(s,i+1,j);
        }
    }
}

int main()
{
    int t; cin>>t;
    while(t--){
        string s; cin >> s;
        sort(s.begin(), s.end());
        permute(s,0,s.length()-1);
        cout << endl;
    }

	return 0;
}