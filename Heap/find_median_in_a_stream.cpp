#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair

using namespace std;

void balance(priority_queue<int, vector<int>, less<int>> &maxh, priority_queue<int, vector<int>, greater<int>> &minh){
    if(maxh.size() > minh.size() && maxh.size() - minh.size() >= 2){
        int n = maxh.top();
        maxh.pop();
        minh.push(n);
    }
    
    if(minh.size() > maxh.size() && minh.size() - maxh.size() >= 2){
        int n = minh.top();
        minh.pop();
        maxh.push(n);
    }
}

int main()
{
    int n; cin >> n;
    
    priority_queue<int, vector<int>, less<int>> maxh;
    priority_queue<int, vector<int>, greater<int>> minh;
    
    for(int i = 0;i < n;i++){
        int num; cin >> num;
        
        if(maxh.size() == 0 || maxh.top() > num) maxh.push(num);
        else minh.push(num);
        
        balance(maxh,minh);
        
        int median = 0;
        
        if(maxh.size() == minh.size()){
            median = (maxh.top() + minh.top())/2;
        }
        else{
            if(maxh.size() > minh.size())
                median = maxh.top();
            else median = minh.top();
        }
        cout << median << endl;
    }

	return 0;
}