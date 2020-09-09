// { Driver Code Starts
 #include <bits/stdc++.h>
using namespace std;

int atoi(string str);
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        cout<<atoi(s)<<endl;
    }
}// } Driver Code Ends


/*You are required to complete this method */
int atoi(string str)
{
    int n = 0;
    bool neg = false;
    int start = 0;
    if(str[0] == '-' && str.length() > 1){
        neg = true;
        start = 1;
    }
    for(int i = start;i < str.length();i++){
        if(str[i]-'0' >= 0 && str[i]-'0' < 10){
            n = n*10 + (int)(str[i]-'0');
        }
        else return -1;
    }
    if(neg) n = -n;
    return n;
    //Your code here
}