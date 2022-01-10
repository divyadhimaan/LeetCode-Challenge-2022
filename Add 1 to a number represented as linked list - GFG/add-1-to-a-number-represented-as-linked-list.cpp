// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h> 
using namespace std; 

struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};

void printList(Node* node) 
{ 
    while (node != NULL) { 
        cout << node->data; 
        node = node->next; 
    }  
    cout<<"\n";
} 


 // } Driver Code Ends
//User function template for C++

/* 

struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};

*/

class Solution
{
    public:
    Node* addOne(Node *head) 
    {
        //reverse the list
        Node* q = NULL;
        Node* p = head;
        Node* r = NULL;
        while (p != NULL) {
            // Store next
            r = q;
            q = p;
            p = p->next;
            q->next = r;
        }
        head=q;
        
        //add one to leftmost and contiue till carry is zero
        p=head;
        while(p!=NULL)
        {
            p->data = (p->data)+1;
            int carry = (p->data/10);
            if(carry!=0)
            {
                if(p->next!=NULL)
                {
                    p->data%=10;
                }
                
                p=p->next;
            }
            else
            break;
        }
        
        //Again reverse the LL
        q=NULL;
        p=head;
        r=NULL;
        while (p != NULL) {
            // Store next
            r = q;
            q = p;
            p = p->next;
            q->next = r;
        }
        head=q;
        
        return head;
    }
};

// { Driver Code Starts.

int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        
        Node* head = new Node( s[0]-'0' );
        Node* tail = head;
        for(int i=1; i<s.size(); i++)
        {
            tail->next = new Node( s[i]-'0' );
            tail = tail->next;
        }
        Solution ob;
        head = ob.addOne(head);
        printList(head); 
    }
    return 0; 
} 
  // } Driver Code Ends