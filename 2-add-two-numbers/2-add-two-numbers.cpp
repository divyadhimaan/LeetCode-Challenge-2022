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
        
        int carry = 0;
        ListNode* head = new ListNode(-1);
        ListNode* curr = head;
        while(l1 || l2)
        {
            int x1 = (l1!=NULL)?l1->val:0;            
            int x2 = (l2!=NULL)?l2->val:0;

            int sum = carry + x1 + x2;
            carry = (sum/10);
            // cout<<sum<<" "<<carry<<endl;
            ListNode* temp = new ListNode(sum%10);
            curr->next = temp;
            curr = temp;
            l1=(l1!=NULL)?l1->next:NULL;           
            l2=(l2!=NULL)?l2->next:NULL;     
        }
        if(carry)
        {
            ListNode* temp = new ListNode(carry);
            curr->next = temp;
            curr = temp;
        }
        
        return head->next;
    }
};