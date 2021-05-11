// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends



class Solution
{
    public:
    //Function to find the maximum number of meetings that can
    //be performed in a meeting room.
    
    static bool comp(const pair<int,int> &a, const pair<int,int> &b){
        if(a.second == b.second) return a.first < b.first;
        else return a.second < b.second;
    }
    
    int maxMeetings(int start[], int end[], int n)
    {
        // Your code here
        vector<pair<int,int>> times;
        
        for(int i = 0;i < n;i++){
            times.push_back({start[i], end[i]});
        }
        
        sort(times.begin(), times.end(), comp);
        
        int cur = times[0].second;
        int cnt = 1;
        
        for(int i = 1;i < n;i++){
            if(times[i].first > cur){
                cur = times[i].second;
                cnt++;
            }
        }
        
        return cnt;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int start[n], end[n];
        for (int i = 0; i < n; i++) cin >> start[i];

        for (int i = 0; i < n; i++) cin >> end[i];

        Solution ob;
        int ans = ob.maxMeetings(start, end, n);
        cout << ans << endl;
    }
    return 0;
}  // } Driver Code Ends