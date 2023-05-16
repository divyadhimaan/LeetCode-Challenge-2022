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
    
    ListNode* reverseList(ListNode* head)
    {
        ListNode* p = head;
        ListNode* q = NULL;
        ListNode* r;
        
        while(p)
        {
            r = q;
            q = p;
            p=p->next;
            q->next = r;
        }
        return q;
    }
    
    void reorderList(ListNode* head) {
        ListNode* fast = head;
        ListNode* slow = head;
        
        while(fast->next && fast->next->next)
        {
            fast=fast->next->next;
            slow=slow->next;
        }
        
        ListNode* head2 = reverseList(slow);
        slow->next = NULL;
        ListNode* tail = head;
        ListNode* tail2 = head2;
                
        while(head && head2)
        {
            tail = head->next;
            head->next = head2;
            tail2 = head2->next;
            head2->next = tail;
            head = tail;
            head2 = tail2;
        }
    }
};