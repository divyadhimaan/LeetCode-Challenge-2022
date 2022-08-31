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
typedef pair<int, ListNode*> node;

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
 

        priority_queue<node, vector<node>, greater<node>> pq;
        
        for(int i=0;i<lists.size();i++)
        {
            if(lists[i])
                pq.push({lists[i]->val, lists[i]});
        }
        ListNode* head = NULL, *tail;
        
        while(!pq.empty())
        {
            auto curr = pq.top();
            pq.pop();
            
            ListNode* temp = curr.second;
            
            if(!head)
                head = temp;
            else
                tail->next = temp;
            
            tail = temp;
            
            if(temp->next)
            {
                pq.push({temp->next->val, temp->next});
            }
        }
        return head;
    }
};