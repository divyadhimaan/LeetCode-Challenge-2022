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
    
    int countNodes(ListNode *head)
    {
        if(!head)
            return 0;
        
        int count=0;
        while(head)
        {
            count++;
            head=head->next;
        }
        return count;
    }
    
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        
        ListNode* p = headA;
        ListNode* q = headB;
        
        if(!p || !q)
            return NULL;
        
        int c1 = countNodes(p);
        int c2 = countNodes(q);
        
        p = headA;
        q = headB;
        
        int d = abs(c1-c2);
        if(c1>c2)
        {
            while(d--)
                p=p->next;
        }else{
            while(d--)
                q = q->next;
        }
        
        while(p && q && p!=q)
        {
            p=p->next;
            q=q->next;
        }
        if(p==q)
            return q;
        
        return NULL;
    }
};