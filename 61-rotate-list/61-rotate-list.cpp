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
    int count(ListNode* head)
    {
            int count =0;
        while(head)
        {
                count++;
            head = head->next;
        }
        return count;
    }
    
    ListNode* rotateRight(ListNode* head, int k) {
        
        int size = count(head);
        if(size==0 || size==k || k==0)
            return head;
        
        // If moves are more than the number of nodes
        if(k>size)
            k = k%size;
        
        int moves = size - k - 1;
        
        ListNode* p = head;
        ListNode* q = NULL;
        while(moves--)
        {
            p =p->next;
        }
        q = p;
        while(p->next)
        {
            p=p->next;
        }
        p->next = head;
        head=q->next;
        q->next = NULL;
        
        return head;
    }
};