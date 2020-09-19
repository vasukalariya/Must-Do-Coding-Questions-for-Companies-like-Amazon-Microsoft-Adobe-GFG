// { Driver Code Starts
// driver

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

/* Linked list Node */
struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

struct Node* buildList(int size)
{
    int val;
    cin>> val;
    
    Node* head = new Node(val);
    Node* tail = head;
    
    for(int i=0; i<size-1; i++)
    {
        cin>> val;
        tail->next = new Node(val);
        tail = tail->next;
    }
    
    return head;
}

void printList(Node* n)
{
    while(n)
    {
        cout<< n->data << " ";
        n = n->next;
    }
    cout<< endl;
}

struct Node* addTwoLists(struct Node* first, struct Node* second);

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, m;
        
        cin>>n;
        Node* first = buildList(n);
        
        cin>>m;
        Node* second = buildList(m);
        
        Node* res = addTwoLists(first,second);
        printList(res);
    }
    return 0;
}
// } Driver Code Ends


/* node for linked list:

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/
int addnum(struct Node* a, struct Node* b){
    
    if(a == nullptr || b == nullptr) return 0;
    
    else{
        
        int carry = addnum(a->next, b->next);
        
        int sum = a->data + b->data + carry;
        carry = sum/10;
        a->data = sum%10;
        
        return carry;
    }
}

int addrest(struct Node* a, int carry, int diff){
    
    int sum;
    
    if(diff == 0){
        
        sum = a->data + carry;
        
        carry = sum/10;
        a->data = sum%10;
        
        return carry;
    }
    
    else{
        
        int new_carry = addrest(a->next,carry,diff-1);
        
        sum = a->data + new_carry;
        new_carry = sum/10;
        a->data = sum%10;
        
        return new_carry;
    }
    
}


struct Node* addTwoLists(struct Node* first, struct Node* second)
{
    
    int fsize = 0;
    int ssize = 0;
    
    Node* t1 = first;
    Node* t2 = second;
    
    while(t1 != NULL){
        t1 = t1->next;
        fsize++;
    }
    while(t2 != NULL){
        t2 = t2->next;
        ssize++;
    }
    
    int res_carry;
    
    if(fsize == ssize){
        
        res_carry = addnum(first,second);
        
        if(res_carry > 0){
            Node* new_node = (struct Node*)malloc(sizeof(struct Node));
        
            new_node->data = res_carry;
            new_node->next = first;
        
            return new_node;
        }

        return first;
    }
    
    else if(fsize > ssize){
        
        int diff = fsize - ssize;
        
        Node* start = first;
        int tdiff = diff;
        
        while(tdiff--){
            start = start->next;
        }
        
        res_carry = addnum(start,second);
        
        if(res_carry > 0) res_carry = addrest(first,res_carry,diff-1);
        
        if(res_carry > 0){
            Node* new_node = (struct Node*)malloc(sizeof(struct Node));
            new_node->data = res_carry;
            new_node->next = first;
            return new_node;
        }
        
        return first;
    }
    
    else{
        
        int diff = ssize - fsize;
        Node* start = second;
        
        int tdiff = diff;
        while(tdiff--){
            start = start->next;
        }
        
        res_carry = addnum(start,first);
        
        if(res_carry > 0) res_carry = addrest(second,res_carry,diff-1);
        
        if(res_carry > 0){
            Node* new_node = (struct Node*)malloc(sizeof(struct Node));
            new_node->data = res_carry;
            new_node->next = second;
            return new_node;
        }
        return second;
    }
    
    // code here
}