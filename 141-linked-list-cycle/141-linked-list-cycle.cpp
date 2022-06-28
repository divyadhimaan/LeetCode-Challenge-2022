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
    bool hasCycle(ListNode *head) {
        ListNode* p = head;
        ListNode* q = head;
        
        if(!p || !p->next)
            return false;
        
        do{
            q=q->next;
            p=p->next;
            p = (p== NULL) ? NULL : p->next;
        }while(p && q && p!=q);
            
        if(p==q)
            return true;
        
        return false;
    }
};