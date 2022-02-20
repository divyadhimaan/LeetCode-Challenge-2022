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
    bool hasCycle(ListNode *head) {
        ListNode *p=head;
        ListNode *q = head;
        
        if(!head || !head->next)
            return false;
        
        do {
            p=p->next;
            q=q->next;
            q=(q!=NULL ? q->next : NULL);
        }while(p && q&& p!=q);
            
        if(p==q)
            return true;
        
        return false;
    }
};