// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

vector <int> countDistinct(int[], int, int);

int main()
{
    int t;
    cin >> t;
    while (t--)
    {

        int n, k;
        cin >> n >> k;
        int a[n];
        for (int i = 0; i < n; i++) 
        	cin >> a[i];
        vector <int> result = countDistinct(a, n, k);
        for (int i : result) 
        	cout << i << " ";
        cout << endl;
    }
    return 0;
}// } Driver Code Ends



vector <int> countDistinct (int A[], int n, int k)
{
    //code here.
    map<int,int> m;
    vector<int> vec;
    
    for(int i = 0;i < k;i++) m[A[i]]++;
    
    vec.push_back(m.size());
    
    for(int i = k;i < n;i++){
        
        if(m[A[i-k]] == 1) m.erase(A[i-k]);
        else m[A[i-k]]--;
        
        m[A[i]]++;
        vec.push_back(m.size());
    }
    
    return vec;
}