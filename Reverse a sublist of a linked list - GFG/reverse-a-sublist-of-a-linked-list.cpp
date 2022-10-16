//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

/* Link list node */
struct Node {
	int data;
	struct Node *next;
	Node(int x) {
		data = x;
		next = NULL;
	}
};


// } Driver Code Ends
//User function Template for C++

/*Link list node 
struct Node {
	int data;
	struct Node *next;
	Node(int x) {
		data = x;
		next = NULL;
	}
};*/

class Solution
{
    public:
    
    
    Node* reverse(Node* head)
    {
        Node* p = head;
        Node* q = NULL;
        Node* r;
        while(p)
        {
            r = q;
            q = p;
            p=p->next;
            q->next = r;
        }
        return q;
    }
    Node* reverseBetween(Node* head, int m, int n)
    {
        int count = 0;
        Node* point1, *point2;
        Node* p = head;
        
        while(p)
        {
            count++;
            if(count == m-1)
            {
                point1 = p;
            }
            if(count == n)
            {
                point2 = p->next;
                p->next = NULL;
                break;
            }
            p=p->next;
        }
        
        if(m==1)
        {
            head = reverse(head);
            point1 = head;
            while(point1->next)
                point1 = point1->next;
                
            point1->next = point2;
        }else{
            Node* rev = point1->next;
            point1->next = reverse(rev);
            rev->next= point2;
        }
        return head;
        
    }
};

//{ Driver Code Starts.

/* Function to print linked list */
void printList(struct Node *head)
{
	struct Node *temp = head;
	while (temp != NULL)
	{
		printf("%d ", temp->data);
		temp = temp->next;
	}
}



// Driver program to test above functions
int main()
{
	int T;
	cin >> T;

	while (T--)
	{
		int N, m, n;
		cin >> N>>m>>n;

		Node *head = NULL;
		Node *temp = head;

		for (int i = 0; i < N; i++) {
			int data;
			cin >> data;
			if (head == NULL)
				head = temp = new Node(data);
			else
			{
				temp->next = new Node(data);
				temp = temp->next;
			}
		}

		

        Solution ob;

		Node* newhead = ob.reverseBetween(head, m, n);
		printList(newhead);

		cout << "\n";



	}
	return 0;
}

// } Driver Code Ends