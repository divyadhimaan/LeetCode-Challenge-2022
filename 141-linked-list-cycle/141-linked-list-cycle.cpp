/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        unordered_set<ListNode *> st;
        
        ListNode* p = head;
        
        while(p)
        {
            if(st.find(p) != st.end())
                return true;
            st.insert(p);
            p=p->next;
        }
        
        return false;
    }
};