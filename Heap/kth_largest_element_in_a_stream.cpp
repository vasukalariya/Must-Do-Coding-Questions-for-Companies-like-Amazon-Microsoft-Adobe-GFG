#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int t; cin>>t;
    while(t--){
        
        int k,n; cin >> k >> n;
        priority_queue<int,vector<int>,greater<int>> minh;
        
        for(int i = 0;i < n;i++){
            int num; cin >> num;
            minh.push(num);
    
            if(minh.size() > k) minh.pop();
            if(minh.size() < k) cout << -1 << " ";    
            else cout << minh.top() << " ";
        }
        cout << endl;
    }
    
	return 0;
}