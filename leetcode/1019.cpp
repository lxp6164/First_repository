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
    //存两个
    ListNode* removeNthFromEnd(ListNode* head, int n)
    {   //2333
        if(head == NULL || head->next == NULL)  return NULL; 
        
        ListNode* p = head;
        ListNode* x = head;
        ListNode* y;// = new ListNode;
        ListNode* z = head;
      
        
        //////////////////////////////////
        //为什么head->next = head->next->next;不对呢？
        //难道链表1,2  的head是1 而不是一个特定的头节点！！！！  ?????
        for(int i=0; i<n; i++)
           z = z->next;
        if(z==NULL) 
        {
            return head->next;
           //head->next = head->next->next;
         //  return head; 
        }
        
        int cnt = 0;
        while(p = p->next)
        {
           // p = p->next;
            
            cnt++;
            if(cnt > n){x = x->next; }

            
        }
        //x,y
        y = x->next;
        x->next = x->next->next;
        delete y;


        return head;
    }
};
