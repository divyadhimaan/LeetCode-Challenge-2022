/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int cA=1,cB=1;
        if(headA==NULL  || headB==NULL)
            return NULL;

        ListNode *p=headA;
        ListNode *q=headB;


        while(p->next!=NULL)
        {
            cA++;
            p=p->next;
        }
        
        while(q->next!=NULL)
        {
            cB++;
            q=q->next;
        }

        int d = abs(cA-cB);
        p=headA;
        q=headB;
        //move larger list 
        if(cA>cB)
        {
            for(int i=0;i<d;i++)
            {
                if(p->next==NULL)
                    return NULL;
                p=p->next;
            }
        }
        else
        {
            for(int i=0;i<d;i++)
            {
                if(q->next==NULL)
                    return NULL;
                q=q->next;
            }
        }

        //now both list have equal nodes left;
        while(p!=NULL || q!=NULL)
        {
            if(p==q)
            return p;
            p=p->next;
            q=q->next;

        }

        return NULL;
    }
};