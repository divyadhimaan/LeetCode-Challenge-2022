/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    
    Node* flatten(Node* head) {
        if(!head)
            return NULL;
        
        Node* p = head;
        Node* q = head;
        // Node* r = NULL;
        stack<Node*> stk;
        
        while(p->next || p->child)
        {
            if(p->child)
            {
                stk.push(p->next);
                p->next = p->child;
                p->child->prev = p;
                p->child = NULL;
            }
            p = p->next;
        }
        
        while(!stk.empty())
        {
            Node* curr = stk.top();
            stk.pop();
            if(curr!=NULL)
            {
                p->next = curr;
                curr->prev = p;
                while(curr->next)
                {
                    curr = curr->next;
                }
                p = curr;
            }
        }
        
        return head;
    }
};