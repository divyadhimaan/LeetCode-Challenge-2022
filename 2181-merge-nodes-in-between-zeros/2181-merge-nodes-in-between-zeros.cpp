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
    ListNode* mergeNodes(ListNode* head) {
        // Pointer to the input linked list's head
        ListNode * firstzero = head->next;
        int sum = 0;
		
		// solution Linked Lists's head
        ListNode * solhead = new ListNode();
		
		// Pointer to solution Linked List's head
        ListNode * soltemp = solhead;
        
        while(firstzero)
        {
            if(firstzero->val)
            {
                sum += firstzero->val;
            }
            else
            {
               ListNode * temp = new ListNode(sum);
                soltemp ->next = temp;
                soltemp = soltemp ->next;
                sum = 0;  
            }
            
            firstzero = firstzero->next;
        }
        
		// Return solution linked lists's head -> next (since solution head's value is not needed)
        return solhead ->next;
        
    }
};