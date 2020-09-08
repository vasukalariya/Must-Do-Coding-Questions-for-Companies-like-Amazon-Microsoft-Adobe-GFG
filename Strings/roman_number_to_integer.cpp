#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair

using namespace std;

int main()
{
    int t; cin>>t;
    
    map<char,int> m;
    m['I'] = 1;
    m['V'] = 5;
    m['X'] = 10;
    m['L'] = 50;
    m['C'] = 100;
    m['D'] = 500;
    m['M'] = 1000;
    
    while(t--){
        
        string s; cin >> s;
        ll total = 0;
        bool last = false;
        for(int i = 0;i < s.length()-1;i+=0){
            if(m[s[i]] >= m[s[i+1]]){
                total += m[s[i]];
                i++;
            }
            else{
                total += (m[s[i+1]]-m[s[i]]);
                i+=2;
                if(i == s.length()){
                    last = true;
                }
            }
        }
        if(!last) total += m[s[s.length()-1]];
        
        cout << total << endl;
    }

	return 0;
}