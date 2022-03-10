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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if(!l1)
            return l2;
        if(!l2)
            return l1;
        
        ListNode* h1 = l1;
        ListNode* h2 = l2;
        ListNode* result = new ListNode(-1);
        ListNode* tail = result;
        int carry =0;
        while(h1 || h2){
            int x = (h1!=NULL) ? h1->val :0;            
            int y = (h2!=NULL) ? h2->val :0;
            int sum = x + y + carry;
            carry = sum/10;
            sum = sum%10;
            tail->next = new ListNode(sum);
            tail=tail->next;
            
            if(h1)
                h1=h1->next;
            if(h2)
                h2=h2->next;
        }
        
        
        if(carry)
        {
            tail->next = new ListNode(carry);
        }
        
        return result->next;
    }
};