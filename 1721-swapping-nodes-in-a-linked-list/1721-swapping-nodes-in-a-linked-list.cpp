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
    
    ListNode* findKthNode(ListNode* head, int k)
    {
        for(int i=1;i<k;i++)
        {
            head=head->next;
        }
        return head;
    }
    
    int countNodes(ListNode* head)
    {
        int count = 0;
        while(head)
        {
            count++;
            head=head->next;
        }
        return count;
    }
    
    ListNode* findKthFromEndNode(ListNode* head, int k)
    {
        int n = countNodes(head);
        
        
        for(int i=1;i<n-k+1;i++)
        {
            head=head->next;
        }
        return head;
    }
    
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode* s = findKthNode(head, k);
        ListNode* e = findKthFromEndNode(head, k);
        
        int temp = s->val;
        s->val = e->val;
        e->val = temp;
        
        return head;
        
        
    }
};