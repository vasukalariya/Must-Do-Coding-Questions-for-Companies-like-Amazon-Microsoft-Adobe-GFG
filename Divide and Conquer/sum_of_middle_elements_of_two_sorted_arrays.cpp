// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

 // } Driver Code Ends
//User function template for C++

class Solution {
public:
    int findMidSum(int ar1[], int ar2[], int n) {
        // code here 
        
        if(n == 1 || ar1[n-1] <= ar2[0]) return ar1[n-1] + ar2[0];
        
        if(ar2[n-1] <= ar1[0]) return ar2[n-1] + ar1[0];
        
        int l = 1,r = n;
        
        while(l <= r){
            int num1 = l + (r-l)/2;
            int num2 = n - num1;
            
            if(ar1[num1-1] <= ar2[num2] && ar2[num2-1] <= ar1[num1])
                return max(ar1[num1-1], ar2[num2-1]) + min(ar1[num1], ar2[num2]);
            else if(ar1[num1-1] > ar2[num2]) r = num1-1;
            else l = num1 + 1;
        }
        
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int ar1[n], ar2[n];
        for (i = 0; i < n; i++) {
            cin >> ar1[i];
        }
        for (i = 0; i < n; i++) {
            cin >> ar2[i];
        }
        Solution ob;
        auto ans = ob.findMidSum(ar1, ar2, n);
        cout << ans << "\n";
    }
    return 0;
}  // } Driver Code Ends