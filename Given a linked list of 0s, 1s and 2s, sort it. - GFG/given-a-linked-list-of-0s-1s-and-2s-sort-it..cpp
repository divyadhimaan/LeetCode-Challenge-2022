// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;
/* Link list Node */
struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

struct Node *start = NULL;


 // } Driver Code Ends
/*
 
  Node is defined as
  struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/
class Solution
{
    public:
    //Function to sort a linked list of 0s, 1s and 2s.
    Node* segregate(Node *head) {
        
        Node* zero =NULL;
        Node* zeroD =zero;
        Node* one =NULL;
        Node* oneD =one;
        Node* two =NULL;
        Node* twoD =two;
        
        Node* curr = head;
        while(curr)
        {
            if(curr->data == 0)
            {
                if(zeroD == NULL)
                {
                    zero = curr;
                    zeroD = curr;
                }else {
                    zeroD -> next= curr;
                    zeroD = curr;
                }
                
            }
            else if(curr->data == 1)
            {
                if(oneD == NULL)
                {
                    one = curr;
                    oneD = curr;
                }else {
                    oneD -> next= curr;
                    oneD = curr;
                }
            }
            else
            {
                if(twoD == NULL)
                {
                    two = curr;
                    twoD = curr;
                }else {
                    twoD -> next= curr;
                    twoD = curr;
                }
            }
            curr = curr->next;
        }
        

        if(zero)
        {
            if(one)
            {
                zeroD->next=one;
                if(two)
                {
                    oneD->next=two;
                    twoD->next=NULL;
                }
                else 
                    oneD->next=NULL;
            }
            else
            {
                if(two)
                {
                    zeroD->next=two;
                    twoD->next=NULL;
                }
                else 
                    zeroD->next=NULL;
            }
        return zero;
        }
        else
        {
            if(one)
            {
                if(two)
                {
                    oneD->next=two;
                    twoD->next=NULL;
                }
                else
                {
                    oneD->next=NULL;
                }
                return one;
            }
            else
            {
                return two;
            }
        }
    }
};


// { Driver Code Starts.

// Function to sort a linked list of 0s, 1s and 2s
void printList(struct Node *Node) {
    while (Node != NULL) {
        printf("%d ", Node->data);
        Node = Node->next;
    }
    printf("\n");
}

/* Drier program to test above function*/
void insert(int n1) {
    int n, value, i;
    // scanf("%d",&n);
    n = n1;
    struct Node *temp;
    for (i = 0; i < n; i++) {
        scanf("%d", &value);

        if (i == 0) {
            start = new Node(value);
            temp = start;
            continue;
        } else {
            temp->next = new Node(value);
            temp = temp->next;
            temp->next = NULL;
        }
    }
}

int main() {

    int n;

    int t;
    scanf("%d", &t);

    while (t--) {
        scanf("%d", &n);

        insert(n);
        Solution ob;
        struct Node *newHead = ob.segregate(start);
        printList(newHead);
    }

    return 0;
}  // } Driver Code Ends