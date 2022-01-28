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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp=head;
        for(int i=0;i<k;i++){
            if(!temp)return head;
            temp=temp->next;
        }
    
        // Step1 : Reverse first k Nodes
        ListNode* curr = head;
        ListNode* prev = NULL;
        ListNode* forward = NULL;
        int cnt=0;
        while(curr != NULL && cnt < k){
            forward = curr->next;
            curr->next = prev;
            prev = curr;
            curr = forward;
            cnt++;
        }

        // Step 2: Recursion dekhlega aage ka
         if(forward)
            head->next = reverseKGroup(forward,k);

        // Step 3 : Return head of reversed linklist
        return prev;
    }
};