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
    ListNode* deleteDuplicates(ListNode* head) {
        
        if(!head)
            return head;
        
        ListNode *curr = head->next;
        ListNode *prev = head;
        
        while(curr)
        {
            if(curr && prev->val == curr->val)
                prev->next = curr->next;
            else
                prev = curr;
            
            curr = curr->next;
        }
        
        return head;
    }
};