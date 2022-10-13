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
    void deleteNode(ListNode* node) {
        ListNode* p = node->next;
        
        while(p->next)
        {
            node->val = p->val;
            p=p->next;
            node=node->next;
        }
        node->val = p->val;
        node->next = NULL;
        
        delete(p);
    }
};