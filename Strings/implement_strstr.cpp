// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

int strstr(string ,string);

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string a;
        string b;
        
        cin>>a;
        cin>>b;
        
        cout<<strstr(a,b)<<endl;
    }
}
// } Driver Code Ends


/* The function should return position where the target string 
   matches the string str
Your are required to complete this method */
int strstr(string s, string x)
{
    if(x.length() > s.length()) return -1;
    else{
        for(int i = 0;i < s.length();i++){
            bool subs = true;
            if(s.length()-i < x.length()){
                return -1;
            }
            for(int j = i;j < s.length() && (j-i) < x.length();j++){
                if(s[j] != x[j-i]){
                    subs = false;
                    break;
                }
            }
            if(subs) return i;
        }
        return -1;
    }
    
     //Your code here
}