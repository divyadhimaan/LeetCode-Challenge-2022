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
    
    ListNode* reverseList(ListNode* head)
    {
        ListNode* p = head;
        ListNode* q = NULL;
        ListNode* r;
        
        while(p)
        {
            r = q;
            q = p;
            p = p->next;
            q->next = r;
        }
        return q;
    }
    
    ListNode* findMid(ListNode* head)
    {
        ListNode* fast = head;
        ListNode* slow = head;
        
        while(fast && fast->next)
        {
            fast = fast->next->next;
            slow = slow->next;
        }
        return slow;
    }
    
    
    int pairSum(ListNode* head) {
    
        //find the mid of the list
        ListNode* mid = findMid(head);
        
        ListNode* head2 = reverseList(mid);
        mid->next = NULL;
        
        int maxSum = -1;
        
        while(head && head2)
        {
            int sum = head->val + head2->val;
            if(sum > maxSum)
                maxSum = sum;
            
            head=head->next;
            head2=head2->next;
        }
        return maxSum;
        
    }
};