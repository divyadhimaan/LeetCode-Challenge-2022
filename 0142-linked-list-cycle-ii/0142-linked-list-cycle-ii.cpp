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
    ListNode *detectCycle(ListNode *head) {
        if(!head || !head->next)
            return NULL;
        
        ListNode* slow = head;
        ListNode* fast = head;
        
        // detect the loop
        do{
            slow=slow->next;
            fast=fast->next;
            fast=(fast!=NULL)?fast->next:NULL;
        }while(fast && slow && slow!=fast);
        
        if(slow!=fast)
            return NULL;
        
        
        fast = head;
        while(slow!=fast)
        {
            fast=fast->next;
            slow=slow->next;
        }
        return slow;
        
    }
};