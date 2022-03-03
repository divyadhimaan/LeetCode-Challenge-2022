// { Driver Code Starts
#include<bits/stdc++.h>

using namespace std;

struct Node
{
    int data;
    Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};


void print(Node *root)
{
    Node *temp = root;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}



 // } Driver Code Ends
/*

The structure of linked list is the following

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
class Solution
{
    public:
    
    Node *compute(Node *head)
    {
        //reverse the list
        Node *p=head;
        Node *q=NULL;
        Node *r=NULL;
        
        while(p)
        {
            r=q;
            q=p;
            p=p->next;
            q->next = r;
        }
        head = q;
        
        p=head;
        Node *max = head;
        while(p!=NULL && p->next!=NULL)
        {
            if(p->next->data < max->data)
            {
                q=p->next;
                p->next=q->next;
                delete q;
            }
            else
            {
                p=p->next;
                max = p;
            }
        }
        
        //reverse the list again
        p=head, q=NULL, r=NULL;
        
        while(p)
        {
            r=q;
            q=p;
            p=p->next;
            q->next = r;
        }
        head = q;
    }
    
};
   


// { Driver Code Starts.

int main()
{
    int T;
	cin>>T;

	while(T--)
	{
		int K;
		cin>>K;
		struct Node *head = NULL;
        struct Node *temp = head;

		for(int i=0;i<K;i++){
		    int data;
		    cin>>data;
			if(head==NULL)
			    head=temp=new Node(data);
			else
			{
				temp->next = new Node(data);
				temp = temp->next;
			}
		}
        Solution ob;
        Node *result = ob.compute(head);
        print(result);
        cout<<endl;
    }
}
  // } Driver Code Ends