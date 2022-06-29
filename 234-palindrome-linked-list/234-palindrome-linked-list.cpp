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
    
    ListNode* reverse(ListNode* head)
    {
        ListNode* p = head;
        ListNode* q = NULL;
        ListNode* r;
        
        if(!head)
            return NULL;
        
        while(p)
        {
            r = q;
            q = p;
            p = p->next;
            q -> next = r;
        }
        
        return q;
    }
    
    
    bool isPalindrome(ListNode* head) {
        if(!head || !head->next)
            return true;
        
        ListNode* slow = head;
        ListNode* fast = head;
        
        // Find the Middle of LL 
        while(fast->next && fast->next->next){
            slow=slow->next;
            fast=fast->next->next;
        }   
    
        // reverse the 2nd half
        slow->next = reverse(slow->next);
    
        slow = slow->next;
    
        // compare both halves
        fast = head;
        while(slow)
        {
            if(fast->val != slow->val)
                return false;
            
            fast=fast->next;
            slow=slow->next;
        }
        return true;
    }
};