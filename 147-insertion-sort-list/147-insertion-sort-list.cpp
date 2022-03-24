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
    ListNode* insertionSortList(ListNode* head) {
        ListNode  *dummy = new ListNode(0,head);
        ListNode * node = head;
        
        while(node->next)
        {
            ListNode *temp = node->next;
            
            for(ListNode *cmp = dummy; cmp->next!=temp; cmp = cmp->next)
            {
                if(temp->val < cmp->next->val)
                {
                    node->next = temp->next;
                    
                    
                    temp->next = cmp->next;
                    cmp->next = temp;
                    break;
                }
            }
        
        
            if(node->next == temp)
                node= node->next;
        
        }
        
        return dummy->next;
    }
};