// { Driver Code Starts
// C++ program to merge k sorted arrays of size n each
#include <bits/stdc++.h>
using namespace std;

// A Linked List node
struct Node
{
	int data;
	Node* next;
	
	Node(int x){
	    data = x;
	    next = NULL;
	}
	
};

Node* mergeKLists(Node* arr[], int N);

/* Function to print nodes in a given linked list */
void printList(Node* node)
{
	while (node != NULL)
	{
		printf("%d ", node->data);
		node = node->next;
	}
	cout<<endl;
}

// Driver program to test above functions
int main()
{
   int t;
   cin>>t;
   while(t--)
   {
	   int N;
	   cin>>N;
       struct Node *arr[N];
       for(int j=0;j<N;j++)
        {
           int n;
           cin>>n;

           int x;
           cin>>x;
           arr[j]=new Node(x);
           Node *curr = arr[j];
           n--;

           for(int i=0;i<n;i++)
           {
               cin>>x;
               Node *temp = new Node(x);
               curr->next =temp;
               curr=temp;
           }
   		}

   		Node *res = mergeKLists(arr,N);
		printList(res);

   }

	return 0;
}
// } Driver Code Ends


/*Linked list Node structure

struct Node
{
	int data;
	Node* next;
	
	Node(int x){
	    data = x;
	    next = NULL;
	}
	
};
*/ 

/* arr[] is an array of pointers to heads of linked lists
  and N is size of arr[]  */
bool comp(Node* a, Node* b){
    return a->data < b->data;
}  
  
  
Node * mergeKLists(Node *arr[], int N)
{
    int n = 0;
    
    for(int i = 0;i < N;i++){
        Node* temp = arr[i];
        while(temp != NULL){
            n++;
            temp = temp->next;
        }
    }
    
    Node* ar[n];
    int j = 0;
    for(int i = 0;i < N;i++){
        Node* temp = arr[i];
        while(temp != NULL){
            ar[j] = temp;
            temp = temp->next;
            j++;
        }
    }
    
    sort(ar,ar+n,comp);
    
    Node* head = ar[0];
    Node* temp = head;
    for(int i = 1;i < n;i++){
        temp->next = ar[i];
        temp = temp->next;
    }
    
    return head;
       // Your code here
}
