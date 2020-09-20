#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair

using namespace std;

int main()
{
    int t; cin>>t;
    while(t--){
        
        string s; cin >> s;
        
        stack<char> st;
        
        for(int i = 0;i < s.length();i++){
            
            if(s[i] == '(' || s[i] == '[' || s[i] == '{') st.push(s[i]);
            else{
                if(!st.empty() && s[i] == ')' && st.top() == '(') st.pop();
                else if(!st.empty() && s[i] == ']' && st.top() == '[') st.pop();
                else if(!st.empty() && s[i] == '}' && st.top() == '{') st.pop();
                else st.push(s[i]);
            }
            
        }
        
        if(st.empty() == true) cout << "balanced" << endl;
        else cout << "not balanced" << endl;
        
    }

	return 0;
}