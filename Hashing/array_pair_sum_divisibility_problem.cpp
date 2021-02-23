// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution {
  public:
    bool canPair(vector<int> nums, int k) {
        // Code here.
        map<int,int> m;
        int n = nums.size();
        
        for(int i = 0;i < n;i++) m[(nums[i]%k)]++;
        
        bool pos = true;
        for(auto x:m){
            if((k%2 == 0 && x.first == (k/2)) || x.first == 0){
                if(x.second%2 != 0){
                    pos = false;
                    break;
                }
            }
            else if(m[x.first] != m[k-x.first]){
                pos = false;
                break;
            }
            else;
        }
        
        return pos;
    }
};

// { Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, k;
        cin >> n >> k;
        vector<int> nums(n);
        for (int i = 0; i < nums.size(); i++) cin >> nums[i];
        Solution ob;
        bool ans = ob.canPair(nums, k);
        if (ans)
            cout << "True\n";
        else
            cout << "False\n";
    }
    return 0;
}  // } Driver Code Ends