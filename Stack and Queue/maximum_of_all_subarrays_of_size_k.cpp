#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair

using namespace std;

int main()
{
    int t; cin>>t;
    while(t--){
        
        int n,k; cin >> n >> k;
        int ar[n];
        
        for(int i = 0;i < n;i++) cin >> ar[i];
        
        list<int> dq;
        
        for(int i = 0;i < k;i++){
            while(!dq.empty() && ar[dq.back()] <= ar[i]) dq.pop_back();
            
            dq.push_back(i);
        }
        
        cout << ar[dq.front()] << " ";
        
        for(int i = k;i < n;i++){
            
            while(!dq.empty() && dq.front() <= i-k) dq.pop_front();
            
            while(!dq.empty() && ar[dq.back()] <= ar[i]) dq.pop_back();
            
            dq.push_back(i);
            
            cout << ar[dq.front()] << " ";
        }
        
        cout << endl;
    }

	return 0;
}