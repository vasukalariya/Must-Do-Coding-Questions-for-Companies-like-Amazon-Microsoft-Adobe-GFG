// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


class Solution
{
    public:
    //Function to find the smallest window in the string s consisting
    //of all the characters of string p.
    
    bool check(char req[], char cur[]){
        for(int i = 0;i < 26;i++){
            if(cur[i] < req[i]) return false;
        }
        return true;
    }
    
    
    string smallestWindow (string s, string p)
    {
        // Your code here
        char req[26] = {0};
        char cur[26] = {0};
        string str;
        for(int i = 0;i < p.length();i++) req[p[i]-'a']++;
        
        int l = 0,r = 0,mn = INT_MAX;
        cur[s[l]-'a']++;
        
        if(p.length() > s.length()) return "-1";
        
        while(l <= r && r < s.length() && l < s.length()){
            if(r-l+1 < p.length()){
                r++;
                if(r == s.length()) break;
                cur[s[r]-'a']++;
            }
            else{
                bool avl = check(req,cur);
                if(avl){
                    if(mn > r-l+1){
                        mn = r-l+1;
                        str = s.substr(l,r-l+1);
                    }
                    cur[s[l]-'a']--;
                    l++;
                }
                else{
                    r++;
                    if(r == s.length()) break;
                    cur[s[r]-'a']++;
                }
            }
        }
        
        if(str.length() == 0) return "-1";
        else return str;
        
    }
};

// { Driver Code Starts.
int main()
 {
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        string pat;
        cin>>pat;
        Solution obj;
        cout<<obj.smallestWindow(s, pat)<<endl;
        
    }
	return 0;
}  // } Driver Code Ends