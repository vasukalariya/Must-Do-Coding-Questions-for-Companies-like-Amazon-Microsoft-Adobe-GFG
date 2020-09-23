#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair

using namespace std;

int main()
{
    int t; cin>>t;
    while(t--){
        
        int n; cin >> n;
        
        map<char,int> m;
        list<char> q;
        
        char c; cin >> c;
        q.push_back(c);
        
        m[c]++;
        cout << c << " ";
        
        for(int i = 1;i < n;i++){
            cin >> c;
    
            if(m[c] == 1){
                if(q.empty()) cout << -1 << " ";
                else{
                    q.remove(c);
                    if(q.empty()) cout << -1 << " ";
                    else cout << q.front() << " ";
                }
            }
            else{
                m[c]++;
                q.push_back(c);
                cout << q.front() << " ";
            }
        }
        
        cout << endl;
    }

	return 0;
}