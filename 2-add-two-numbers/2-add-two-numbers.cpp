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
        while(h1 && h2){
            int sum = h1->val + h2->val + carry;
            carry = sum/10;
            sum = sum%10;
            ListNode* temp = new ListNode(sum);
            tail->next = temp;
            tail=tail->next;
            
            h1=h1->next;
            h2=h2->next;
        }
        
        while(h1)
        {
            int sum = h1->val + carry;
            carry = sum/10;
            sum = sum%10;
            ListNode* temp = new ListNode(sum);
            tail->next = temp;
            tail=tail->next;
            
            h1=h1->next;
        }
        while(h2)
        {
            int sum = h2->val + carry;
            carry = sum/10;
            sum = sum%10;
            ListNode* temp = new ListNode(sum);
            tail->next = temp;
            tail=tail->next;
            
            h2=h2->next;
        }
        
        if(carry)
        {
            ListNode* temp = new ListNode(carry);
            tail->next = temp;
        }
        
        return result->next;
    }
};