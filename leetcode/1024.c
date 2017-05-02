/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* swapPairs(struct ListNode* head) 
{
    struct ListNode *p = head;
    struct ListNode *s;
    if(p!=NULL && p->next!=NULL)
    {
        s = p->next;
        p->next = s->next;
        s->next = p;
        
        head = s;
    
      while(p->next!=NULL && p->next->next!=NULL)
      {
          s = p->next->next;
          //s->next = p->next;
          p->next->next = s->next;
          s->next = p->next;
          p->next = s;
        
          //////???!!!!好好推理，s->next = p->next;说明以前的p变成了当前的s
          p = s->next;
      }
          
    }
    return head;

    
}
