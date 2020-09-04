#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair

using namespace std;

int main()
{
    int t; cin>>t;
    while(t--){
        
        ll len; cin >> len;
        ll height[len];
        
        for(int i = 0;i < len;i++) cin >> height[i];
        
        if(len < 3) return 0;
        ll l = 0,r = len-1;
        ll vol = (len-2)*(min(height[l],height[r]));
        ll mnh = min(height[l], height[r]);
        
        while(l+1 < r){
            
            if(height[l] < height[r]){
                l++;
                if(height[l] > mnh){
                    vol -= mnh;
                    vol += (r-l-1)*(min(height[l], height[r])-mnh);
                    mnh = max(min(height[l], height[r]), mnh);
                    
                }
                else vol -= height[l];
            }
            
            else{
                r--;
                if(height[r] > mnh){
                    vol -= mnh;
                    vol += (r-l-1)*(min(height[l], height[r])-mnh);
                    mnh = max(min(height[l], height[r]), mnh);
                }
                else vol -= height[r];
            }
        }
        
        cout << vol << "\n";
    }

    return 0;
}