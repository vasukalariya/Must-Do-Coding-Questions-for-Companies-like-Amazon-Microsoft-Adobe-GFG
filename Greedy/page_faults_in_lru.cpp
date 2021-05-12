// { Driver Code Starts
// Initial Template for C++



#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int pageFaults(int N, int C, int pages[]){
        // code here
        list<int> cache;
        map<int,bool> mp;
        
        int cnt = 0;
        
        for(int i = 0;i < N;i++){
            if(mp[pages[i]] == false){
                cnt++;
                if(cache.size() == C){
                    int bk = cache.back();
                    mp[bk] = false;
                    cache.pop_back();
                    cache.push_front(pages[i]);
                    mp[pages[i]] = true;
                }
                else{
                    cache.push_front(pages[i]);
                    mp[pages[i]] = true;
                }
            }
            else{
                cache.erase(remove(cache.begin(), cache.end(), pages[i]), cache.end());
                cache.push_front(pages[i]);
            }
        }
        
        return cnt;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N, C;
        cin>>N;
        int pages[N];
        for(int i = 0;i < N;i++)
            cin>>pages[i];
        cin>>C;
        
        Solution ob;
        cout<<ob.pageFaults(N, C, pages)<<"\n";
    }
    return 0;
}  // } Driver Code Ends