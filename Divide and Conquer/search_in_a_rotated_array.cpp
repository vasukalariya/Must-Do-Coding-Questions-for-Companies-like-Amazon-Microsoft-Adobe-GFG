// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
    public:
    int search(int A[], int l, int h, int key){
        //complete the function here
        
        while(l <= h){
            int mid = l + (h-l)/2;
            if(A[mid] == key) return mid;
            if(A[l] > A[mid]){
                if(A[mid] < key && key < A[l]) l = mid+1;
                else h = mid-1;
            }
            else{
                if(A[mid] > key && key >= A[l]) h = mid-1;
                else l = mid+1;
            }
        }
        if(A[l] == key) return l;
        else return -1;
    }
};

// { Driver Code Starts. 
int main() {
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int A[n];
        for(int i = 0; i < n; i++)
            cin >> A[i];
        int key;
        cin >> key;
        Solution ob;
        cout << ob.search(A, 0, n - 1, key) << endl;
    }
return 0;
}  // } Driver Code Ends