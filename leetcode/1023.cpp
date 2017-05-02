/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 *     //或在结构体里重载<
 *     bool operator <(const Listnode &rhs)const
 *     {
 *        return val > rhs.val;
 *     }
 *     //不过不是指针类型，还是在外面定义好
 *    
 * };
 */
 
 

 struct cmp
 {  
    bool operator()(const ListNode*p, const ListNode* q)const
    {  
        return p->val > q->val;  //大于？？  
    }  
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode head(-1);
        //传引用
        ListNode* p= &head;
        
        priority_queue<ListNode*,vector<ListNode*>,cmp> q;

        vector<ListNode*>::iterator iter=lists.begin();
        int len = lists.size();

        for(int i=0; i<len; i++)
            if(lists.at(i)) q.push(lists.at(i));
        
        
        while(q.size())
        {
            ListNode* temp = q.top();
            p->next = temp;
            p = p->next;
            
            q.pop();
            
            if(temp->next)
              q.push(temp->next);
        }
        p->next = NULL;
        return head.next;
    }
};
