#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll merge(ll ar[], ll l, ll m, ll r){
    
    ll temp[r-l+1];
    
    ll inv_cnt = 0;
    
    ll i = l, mid = m, j = m+1, k = 0;
    while(i <= mid && j <= r){
        if(ar[i] <= ar[j]){
            temp[k++] = ar[i++];
        }
        else{
            temp[k++] = ar[j++];
            inv_cnt += mid-i+1;
        }
    }
    
    while(i <= mid) temp[k++] = ar[i++];
    while(j <= r) temp[k++] = ar[j++];
    k = 0;
    for(int id = l;id <= r;id++) ar[id] = temp[k++];
    
    return inv_cnt;
}

ll mergesort(ll ar[], ll l, ll r){

    ll mid = (l+r)/2;
    ll inv_cnt = 0;
    if(l < r){
        inv_cnt += mergesort(ar, l, mid);
        inv_cnt += mergesort(ar, mid+1, r);
    }
    inv_cnt += merge(ar,l,mid,r);
    
    return inv_cnt;
}

int main()
{
    int t; cin>>t;
    while(t--){
        ll n; cin >> n;
        ll ar[n];
        
        for(int i = 0;i < n;i++) cin >> ar[i];
        
        ll total = mergesort(ar, 0, n-1);
        cout << total << endl;
    }

	return 0;
}