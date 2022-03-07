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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode *h1 = list1;
        ListNode *h2 = list2;
        ListNode *h3 = NULL;
        ListNode *tail = NULL;
        
        if(!h1)
            return h2;
        if(!h2)
            return h1;
        
        if(h1->val <= h2->val)
        {
            h3 = h1;
            tail = h3;
            h1 = h1->next;
        } else{
            h3 = h2;
            tail = h3;
            h2 = h2->next;
        }
        
        while(h1 && h2)
        {
            if(h1->val <= h2->val)
            {
                tail->next = h1;
                tail = h1;
                h1 = h1->next;
            } else{
                tail->next = h2;
                tail = h2;
                h2 = h2->next;
            }
        }
        if(h1)
            tail->next = h1;
        if(h2)
            tail->next = h2;
        
        return h3;
    }
};