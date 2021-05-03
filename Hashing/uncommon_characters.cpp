// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

class Solution
{
    public:
        string UncommonChars(string A, string B)
        {
            // code here
            map<char,bool> m1;
            map<char,bool> m2;
            set<char> s;
            string str = "";
            
            for(int i = 0;i < A.length();i++) m1[A[i]] = true;
            for(int i = 0;i < B.length();i++) m2[B[i]] = true;
            
            for(int i = 0;i < A.length();i++){
                if(!m2[A[i]]) s.insert(A[i]);
            }
            
            for(int i = 0;i < B.length();i++){
                if(!m1[B[i]]) s.insert(B[i]);
            }
            
            for(auto it = s.begin();it != s.end();it++){
                str += *it;
            }
            
            if(str.length() == 0) return "-1";
            return str;
        }
};



// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string A,B;
        cin>>A;
        cin>>B;
        Solution ob;
        cout<<ob.UncommonChars(A, B);
        cout<<endl;
    }
    return 0;
}  // } Driver Code Ends