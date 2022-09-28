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
    
    int findLength(ListNode* p)
    {
        int count=0;
        while(p)
        {
            count++;
            p=p->next;
        }
        return count;
    }
    
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int length = findLength(head);
        
        if(n==length)
            return head->next;
        
        int fromStart = length - n + 1;
        
        ListNode *p = head;
        for(int i=1;i<fromStart-1;i++)
        {
            p = p->next;
        }
        p->next = p->next->next;
        
        return head;
    }
};