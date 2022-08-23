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
    
    ListNode* reverse(ListNode* head)
    {
        ListNode* p = head;
        ListNode* q = NULL;
        ListNode* r;
        
        while(p)
        {
            r=q;
            q=p;
            p=p->next;
            q->next = r;
        }
        return q;
    }
    
    int count(ListNode* A)
    {
        int c = 0;
        while(A)
        {
            c++;
            A=A->next;
        }
        return c;
    }
    
    bool isPalindrome(ListNode* head) {
        int len = count(head);
        
        ListNode* head2 = head;
        
        int k=0;
        while(k<len/2)
        {
            head2=head2->next;
            k++;
        }
        
        head2 = reverse(head2);
        
        while(head && head2)
        {
            if(head->val != head2->val)
                return false;
            
            head=head->next;
            head2=head2->next;
        }
        return true;
    }
};