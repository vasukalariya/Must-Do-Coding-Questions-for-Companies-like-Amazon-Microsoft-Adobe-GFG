#include<iostream>
#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair

using namespace std;

bool cmp(pair<int,int> a, pair<int,int> b){
    if(a.second == b.second) return a.first < b.first;
    return a.second > b.second;
}

int main()
{
    int t; cin>>t;
    while(t--){
        
        map<int,int> m;
        int n; cin >> n;
        vector<pair<int,int>> vec;
        for(int i = 0;i < n;i++){
            int num; cin >> num;
            m[num]++;
        }
        
        for(auto x:m){
            vec.pb(mp(x.first,x.second));
        }
        
        sort(vec.begin(), vec.end(), cmp);
        
        for(auto x:vec){
            for(int i = 0;i < x.second;i++) cout << x.first << " ";
        }
        cout << endl;
    }

	return 0;
}