// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends

class Solution{
public:
    string chooseandswap(string a){
        // Code Here
        
        int occur[26];
        memset(occur,-1,sizeof(occur));
        
        for(int i = 0;i < a.length();i++){
            if(occur[a[i]-'a'] == -1) occur[a[i]-'a'] = i;
        }
        
        bool flag = false;
        char s,l;
        
        for(int i = 0;i < a.length();i++){
            for(int j = 0;j < a[i]-'a';j++){
                if(occur[a[i]-'a'] < occur[j]){
                    s = 'a'+j;
                    l = a[i];
                    flag = true;
                    break;
                }
            }
            if(flag) break;
        }
        
        if(!flag) return a;
        
        string nstring;
        for(int i = 0;i < a.length();i++){
            if(a[i] == l) nstring += s;
            else if(a[i] == s) nstring += l;
            else nstring += a[i];
        }
        
        return nstring;
    }
    
};


// { Driver Code Starts.

int main()
{
    Solution obj;
	int t;
	cin >> t;
	while(t--)
	{	
	    string a;
		cin >> a;
		cout << obj.chooseandswap(a) << endl;
	}
	return 0;
}
  // } Driver Code Ends