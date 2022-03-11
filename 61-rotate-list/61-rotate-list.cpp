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
    
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head)
            return NULL;
        if(k==0)
            return head;
        
        ListNode* p = head;
        
        int c=0;
        while(p)
        {
            c++;
            p=p->next;
        }
        
        k=k%c;
        
        p=head;
        
        while(p->next)
        {
            p = p->next;
        }
        p->next = head;
        
        p = head;
        for(int i=0;i<(c-k-1);i++)
        {
            p=p->next;
        }
        
        head = p->next;
        p->next = NULL;
        
        return head;
    }
};