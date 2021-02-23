#include<iostream>
#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair

using namespace std;

int main()
{
    int t; cin>>t;
    while(t--){
        
        int m, n; cin >> m >> n;
        
        map<int,bool> mp;
        
        for(int i = 0;i < m;i++){
            int num; cin >> num;
            mp[num] = true;
        }
        
        bool avail = true;
        for(int i = 0;i < n;i++){
            int num; cin >> num;
            if(mp[num] == false){
                avail = false;
            }
        }
        
        if(avail) cout << "Yes" << endl;
        else cout << "No" << endl;
        
        mp.clear();
    }

	return 0;
}