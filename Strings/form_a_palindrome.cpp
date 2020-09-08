#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair

using namespace std;

string s;
int dp[50][50];

int lps(int i, int j){
    
    if(i == j) return 1;
    if(i > j) return 0;
    if(dp[i][j] != -1) return dp[i][j];
    else{
        if(s[i] == s[j]) return dp[i][j] = 2+lps(i+1,j-1);
        else{
            return dp[i][j] = max(lps(i+1,j),lps(i,j-1));
        }
    }
}

int main()
{
    int t; cin>>t;
    while(t--){
        memset(dp, -1, sizeof dp);
        cin >> s;
        cout << (s.length()-lps(0,s.length()-1)) << endl;
        
    }

    return 0;
}