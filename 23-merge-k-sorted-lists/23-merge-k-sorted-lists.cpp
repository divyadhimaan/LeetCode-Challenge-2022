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
    ListNode* mergeTwoLists(ListNode* a, ListNode* b){
        if(a==NULL) return b;
        if(b==NULL) return a;
        ListNode* head=NULL;
        if(a->val <= b->val)
        {   head=a;
            head->next = mergeTwoLists(a->next, b);
            
        }
        else{
            head=b;
            head->next = mergeTwoLists(a, b->next);
            
        }
        return head;
    }
    
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size()==0){
            return NULL;
        }
        if(lists.size()==1){
            return lists[0];
        }
        
        ListNode* res=lists[0];
        
        for(int i=1;i<lists.size();i++){
            res=mergeTwoLists(res,lists[i]);
            
        }
        return res;
    }
};