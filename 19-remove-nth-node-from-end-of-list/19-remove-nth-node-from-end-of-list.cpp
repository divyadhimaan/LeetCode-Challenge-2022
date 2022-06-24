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
    
    int countNodes(ListNode* head)
    {
        int count=0;
        while(head)
        {
            count++;
            head = head->next;
        }
        
        return count;
    }
    
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int count = countNodes(head);
        ListNode* p = head;
        
        if(n>count)
            return head;
        
        if(n==count)
            return head->next;
        
        else{
            int k = count-n+1;
        
            while((k-1)>1)
            {
                p=p->next;
                k--;
            }
            p->next = p->next->next;
        }
        
        return head;
    }
};