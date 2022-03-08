// { Driver Code Starts
// driver

#include <bits/stdc++.h>
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

class Solution
{
    public:
    //Function to add two numbers represented by linked list.
    struct Node* reverse(struct Node* head)
    {
        struct Node* p = head;
        struct Node* q = NULL;
        struct Node* r = NULL;
        
        while(p)
        {
            q=p;
            p=p->next;
            q->next = r;
            r = q;
        }
        
        return q;
    }
    
    struct Node* addTwoLists(struct Node* first, struct Node* second)
    {
        if(!first)
            return second;
        if(!second)
            return first;
            
        struct Node* p = reverse(first);
        struct Node* q = reverse(second);
        
        struct Node* third = new Node(-1);
        struct Node* tail = third;
        
        int carry = 0;
        while(p && q)
        {
            int sum = p->data + q->data + carry;
            carry = sum/10;
            sum = sum%10;
            
            struct Node* temp = new Node(sum);
            tail->next = temp;
            tail = temp;
            
            p=p->next;
            q=q->next;
        }
        
        while(p)
        {
            int sum = p->data + carry;
            carry = sum/10;
            sum=sum%10;
            
            struct Node* temp = new Node(sum);
            tail->next = temp;
            tail = temp;
            p=p->next;
        }
            
        while(q)
        {
            int sum = q->data + carry;
            carry = sum/10;
            sum=sum%10;
            
            struct Node* temp = new Node(sum);
            tail->next = temp;
            tail = temp;
            q=q->next;
        }
        
        if(carry)
        {
            struct Node* temp = new Node(carry);
            tail->next = temp;
        }
            
        return reverse(third->next);
    }
};


// { Driver Code Starts.

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
        Solution ob;
        Node* res = ob.addTwoLists(first,second);
        printList(res);
    }
    return 0;
}
  // } Driver Code Ends