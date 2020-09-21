// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


// design the class:

class LRUCache
{
private:
    int capacity;
    list<int> dq;
    unordered_map<int,pair<int, list<int>::iterator>> m;
    
public:
    LRUCache(int cap)
    {
        capacity = cap;
        dq.clear();
        m.clear();
        // constructor for cache
    }
    
    int get(int key)
    {
        if(m.find(key) == m.end()) return -1;
        else{
            auto it = m.find(key);
            dq.erase(it->second.second);
            dq.push_front(key);
            m[key].second = dq.begin();
            return m[key].first;
        }
        
        // this function should return value corresponding to key
    }
    
    void set(int key, int value)
    {
        if(m.find(key) == m.end())
        {
            if(dq.size() == capacity){
                int rele = dq.back();
                dq.pop_back();
                m.erase(rele);
            }
            
            dq.push_front(key);
            m[key].first = value;
            m[key].second = dq.begin();
            
        }
        else{
            auto it = m.find(key);
            dq.erase(it->second.second);
            dq.push_front(key);
            m[key].first = value;
            m[key].second = dq.begin();
        }
        // storing key, value pair
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {

        int capacity;
        cin >> capacity;
        LRUCache *cache = new LRUCache(capacity);
        
        int queries;
        cin >> queries;
        while (queries--)
        {
            string q;
            cin >> q;
            if (q == "SET")
            {
                int key;
                cin >> key;
                int value;
                cin >> value;
                cache->set(key, value);
            }
            else
            {
                int key;
                cin >> key;
                cout << cache->get(key) << " ";
            }
        }
        cout << endl;
    }
    return 0;
}
  // } Driver Code Ends