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
        ListNode* head;
        ListNode* tail;
        
        ListNode* p = list1;
        ListNode* q = list2;
        
        if(!p && !q)
            return NULL;
        
        if(!p)
            return q;
        if(!q)
            return p;
        
        if(p->val < q->val)
        {
            head = p;
            tail = head;
            p = p->next;
        }else{
            head = q;
            tail = head;
            q = q->next;
        }
        
        while(p && q)
        {
            if(p->val < q->val){
                tail->next = p;
                tail = tail->next;
                p = p->next;
            }else {
                tail->next = q;
                tail =  tail->next;
                q = q->next;
            }
        }
        
        if(p){
            tail->next = p;
        }
        if(q){
            tail->next = q;
        }
        
        return head;
        
    }
};