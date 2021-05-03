// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template for C++
class Solution{
public:	

    bool allsame(int cnt[]){
        
        int same = 0,i;
        for(i = 0;i < 26;i++){
            if(cnt[i] > 0){
                same = cnt[i];
                break;
            }
        }
        
        for(int j = i+1;j < 26;j++){
            if(cnt[j] > 0 && cnt[j] != same){
                return false;
            }
        }
        
        return true;
    }

	bool sameFreq(string s)
	{
	    // code here
	    
	    int cnt[26] = {0};
	    
	    for(int i = 0;i < s.length();i++){
	        cnt[s[i]-'a']++;
	    }
	    
	    if(allsame(cnt)) return true;
	    
	    for(int i = 0;i < 26;i++){
	        if(cnt[i] > 0){
	            cnt[i]--;
	            if(allsame(cnt)) return true;
	            cnt[i]++;
	        }
	    }
	    
	    return false;
	    
	}
};

// { Driver Code Starts.
int main(){
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        Solution ob;
        cout<<ob.sameFreq(s)<<endl;
    }
}


  // } Driver Code Ends