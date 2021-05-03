// { Driver Code Starts
// C++ implementation to find the character in first 
// string that is present at minimum index in second
// string
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends



class Solution
{
    public:
    //Function to find the minimum indexed character.
    int minIndexChar(string str, string patt)
    {
        // Your code here
        map<char,int> m;
        
        for(int i = 0;i < str.length();i++){
            if(m[str[i]] == 0) m[str[i]] = i+1;
        }
        
        int imin = 100100;
        
        
        for(int i = 0;i < patt.length();i++){
            if(m[patt[i]] > 0 && imin > m[patt[i]]){
                imin = m[patt[i]];
            }
        }
        if(imin == 100100) return -1;
        return imin-1;
    }
};

// { Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    string str;
	    string patt;
	    cin>>str;
	    cin>>patt;
	    Solution obj;
	    int ans = obj.minIndexChar(str, patt);
	    if(ans == -1)cout<<"No character present";
	    else cout<<str[ans];
	    cout<<endl;
	}return 0;
}
  // } Driver Code Ends