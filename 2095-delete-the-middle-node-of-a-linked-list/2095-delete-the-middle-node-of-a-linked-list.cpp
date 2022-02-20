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
        ListNode* p=head;        
        ListNode* q=head;
        ListNode* prev_q=NULL;

        if(!head || !head->next)
            return NULL;
        
        while(p && p->next)
        {
            p = p->next->next;
            prev_q = q;
            q = q->next;
        }
        prev_q->next = prev_q->next->next;
        
        return head;
    }
};