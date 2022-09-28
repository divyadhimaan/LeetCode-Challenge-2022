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
    
    ListNode* deleteMiddle(ListNode* head) {
        if(!head || !head->next)
            return NULL;
        
        ListNode* p = head;
        ListNode* q = head;
        ListNode* r;
        while(p && p->next)
        {
            r = q;
            q=q->next;
            p=p->next->next;
        }
        
        r->next = r->next->next;
        return head;
    }
};