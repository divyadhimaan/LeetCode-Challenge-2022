/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    
    int getCount(ListNode* head)  
    {  
        int count = 0; // Initialize count  
        ListNode* current = head; // Initialize current  
        while (current != NULL)  
        {  
            count++;  
            current = current->next;  
        }  
        return count;  
    } 
    
    ListNode* swapNodes(ListNode* head, int K) {
        
        int num = getCount(head);
        
        ListNode *p=head;
        ListNode *q=NULL;

        if(head==NULL ||head->next==NULL)
        return head;

        //if k is valid
        if(K>num)
        return head;

        //if k and (n-k+1) are on same node
        if (2 * K - 1 == num) 
            return head;

        ListNode *t=NULL;
        for(int i=0;i<K-1;i++)
        {
            t=p;
            p=p->next;
        }

        q=head;
        // count2=count1;
        int k=(num-K+1);
        ListNode *r=NULL;
        for(int i=0;i<k-1;i++)
        {
            r=q;
            q=q->next;
        }
        if(t)
        t->next = q;

        if(r)
        r->next = p;


        ListNode *c = p->next;
        p->next = q->next;
        q->next = c;

        if (K == 1) 
            head = q; 
        if (K == num) 
            head = p; 

        return head;
    }
};