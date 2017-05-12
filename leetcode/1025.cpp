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

    //反转，将新的节点插入在前面
    ListNode* insert_front(ListNode* new_Node, ListNode* new_head)
    {
        new_Node->next = new_head;
        return new_Node;
        
        
    }
    
    int getlength(ListNode* p)
    {
        int len = 0;
        while(p)
        {
            len++;
            p = p->next;
            
        }
        return len;
    }


    ListNode* reverseKGroup(ListNode* head, int k) 
    {
        ListNode* p = head;
        
        //不能这样求长度???
        //实践证明可以，head并没有变
        int len = 0;
        while(p)
        {
            len++;
            p = p->next;
        }
        
        //int len = getlength(head);
        
        if(len<k) return head;
        
        ListNode ans(-1);
        ListNode* temp = &ans;
        ListNode* temp_head = NULL;
        ListNode* temp_Node;
        while(len>=k)
        {   
            temp_head = NULL;
            for(int i=0; i<k; i++)
            {    //忘记了...
                temp_Node = head;
                //
                head = head->next;
                //因为这一句,head=head->nex必须放在前面
                temp_Node->next = NULL;
                temp_head = insert_front(temp_Node,temp_head);
                

            }
            
            //先付给temp，在将节点移到后面啊！！！
            temp->next = temp_head;
            //while(temp)不对
            while(temp->next) 
              temp = temp->next;

            
            len -= k;
        }
        //最后剩余的
        if(head)
            temp->next = head;
        
        
      return ans.next;
           
    }
};

