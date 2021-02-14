// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

vector<vector<int> > fourSum(vector<int> &a, int k);

// Position this line where user code will be pasted.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k, i;
        cin >> n >> k;
        vector<int> a(n);
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        vector<vector<int> > ans = fourSum(a, k);
        for (auto &v : ans) {
            for (int &u : v) {
                cout << u << " ";
            }
            cout << "$";
        }
        if (ans.empty()) {
            cout << -1;
        }
        cout << "\n";
    }
    return 0;
}// } Driver Code Ends


// User function template for C++

// arr[] : int input array of integers
// k : the quadruple sum required
vector<vector<int> > fourSum(vector<int> &arr, int k) {
    // Your code goes here
    int n = arr.size();
    sort(arr.begin(), arr.end());
        
    vector<vector<int>> vec;
    
    for(int i = 0;i < n-3;i++){
        
        if(i != 0 && arr[i] == arr[i-1]) continue;
        
        for(int j = i+1;j < n-2;j++){
            
            if(j != i+1 && arr[j] == arr[j-1]) continue;
            
            int left = j+1;
            int right = n-1;
            
            while(left < right){
                
                int total = arr[i] + arr[j] + arr[left] + arr[right];
                
                if(total < k){
                    left++;
                }
                else if(total > k){
                    right--;
                }
                else{
                    vector<int> v;
                    v.push_back(arr[i]);
                    v.push_back(arr[j]);
                    v.push_back(arr[left]);
                    v.push_back(arr[right]);
                    left++;
                    right--;
                    vec.push_back(v);
                    while(left < right && arr[left] == arr[left-1]) left++;
                    while(left < right && arr[right] == arr[right+1]) right--;
                }

            }
            
        }
        
    }
    
    return vec;
}