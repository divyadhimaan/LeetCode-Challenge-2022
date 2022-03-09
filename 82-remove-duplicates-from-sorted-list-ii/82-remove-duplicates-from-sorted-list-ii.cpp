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
        
        if(!head || !head->next)
            return head;
        
        ListNode* prev = new ListNode(-101);
        prev->next = head;
        ListNode* new_head = prev;
        
        
        ListNode* curr = head;
        
        while(curr)
        {
            if(curr && curr->next && curr->val == curr->next->val)
            {
                while(curr && curr->next && curr->val == curr->next->val){
                    curr = curr->next;
                }
                prev->next = curr->next;
            curr = curr->next;
            }
            else {
                curr=curr->next;
                prev=prev->next;
            }
            
        }
        
        return new_head->next;
    }
};