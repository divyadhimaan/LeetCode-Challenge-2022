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
        ListNode* p = headA;
        ListNode* q = headB;
        
        while(p!=q)
        {
            p = (p==NULL) ? p = headB : p->next;
            q = (q==NULL) ? q = headA : q->next;
        }
        
        return q;
    }
};