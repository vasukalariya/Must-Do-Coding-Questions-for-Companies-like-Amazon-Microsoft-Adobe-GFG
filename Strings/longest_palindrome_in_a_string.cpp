#include<bits/stdc++.h>

using namespace std;

string s;

string mxpal(int i, int j){
    while(i >= 0 && j < s.length()){
        if(s[i] == s[j]){
            i--;
            j++;
        }
        else break;
    }
    i++; j--;
    return s.substr(i,j-i+1);
}


int main()
{
    int t; cin>>t;
    while(t--){
        cin>>s;
        string ms;
        ms += s[0];
        int maxlen = 1;
        for(int i = 0;i < s.length()-1;i++){
            string odd = mxpal(i,i);
            string even = mxpal(i,i+1);
            
            if(odd.length() > even.length() && odd.length() > maxlen){
                ms = odd;
                maxlen = odd.length();
            }
            if(odd.length() < even.length() && even.length() > maxlen){
                ms = even;
                maxlen = even.length();
            }
        }
        cout<<ms<<endl;
    }
    
	return 0;
}