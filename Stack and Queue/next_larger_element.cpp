#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair

using namespace std;

int main()
{
    ll t; cin>>t;
    while(t--){
        
        ll n; cin >> n;
        ll ar[n];
        
        for(ll i = 0;i < n;i++) cin >> ar[i];
        
        ll g[n];
        
        stack<ll> st;
        
        st.push(0);
        ll i = 1;
        
        while(i < n){
            while(!st.empty() && ar[st.top()] < ar[i])
            {
                g[st.top()] = ar[i];
                st.pop();
            }
            st.push(i);
            i++;
        }
        
        while(!st.empty()){
            g[st.top()] = -1;
            st.pop();
        }
        
        for(ll j = 0;j < n;j++) cout << g[j] << " ";
        cout << endl;
    }

    return 0;
}