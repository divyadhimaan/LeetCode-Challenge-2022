int c1 = countNodes(p);
int c2 = countNodes(q);
p = headA;
q = headB;
int d = abs(c1-c2);
if(c1>c2)
{
while(d--)
p=p->next;
}else{
while(d--)
q = q->next;
}
while(p && q && p!=q)
{
p=p->next;
q=q->next;
}
if(p==q)
return q;
return NULL;
}
};
```
​
**Approach 2:**
​
​