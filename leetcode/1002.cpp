/* 
*struct ListNode { 
*     int val; 
*     ListNode *next; 
*     ListNode(int x) : val(x), next(NULL) {} 
*}; 
*/  
  
class Solution
{  
public:  
    ListNode* addTwoNumbers(ListNode *l1, ListNode *l2)
    {
      if(l1==NULL && l2==NULL) return NULL;

      unsigned long long x = 0;
      unsigned long long y = 0;
      unsigned long long sum = 0;
      // int cnt1 = 0;
      // int cnt2 = 0;//记录是第几个数

      unsigned long long  yinzi1 = 0;
      //   while(l1->next != NULL)
      while(l1 != NULL)
      {
        if(yinzi1 == 0) yinzi1 = 1;
         else yinzi1 *= 10;

        x = x + yinzi1*(l1->val);
        l1 = l1->next;
      }
      
      unsigned long long yinzi2 = 0;
      // while(l2->next != NULL)
      while(l2 != NULL)
      {
        if(yinzi2 == 0) yinzi2 = 1;
         else yinzi2 *= 10;

        y = y + yinzi2*(l2->val);
        l2 = l2->next;
      }

      sum = x + y;
      /*
      //有多少个数
      long long digit_cnt = 0;
      long long s1 = sum;
      while(s1)
      {
        digit_cnt++;
        s1 /= 10;
      }
      */

      unsigned long long s2 = sum;
      unsigned long long value = s2 % 10;
      ListNode* p = new ListNode(value);
      ListNode* ans = p;
       
      s2 = s2/10;
      while(s2)
      {
        value = s2 % 10;
        //   p->val = t;
        p->next = new ListNode(value) ;//!!!!!!!!!!!!!!!!!!!!
        p = p->next;

        s2 = s2/10;
        //  digit_cnt--;
      }

      return ans;
      
    }
};
