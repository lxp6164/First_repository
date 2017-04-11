//水体＝题，直接在上面写就过了
class Solution {
public:
    bool isPalindrome(int x) 
    {
        if(x<0) return false;
        int cnt = 0;
        int n1 = x;
        int n2 = x;
        
        //int a,b;
        while(n1)
        {
            n1 = n1/10;
            cnt++;
        }
        //有cnt位
        int a = 0;
        int t;
        for(int i=cnt; cnt!=0; cnt--)
        {
            t = n2%10;
            int f = 1;
            for(int j=1; j!=cnt; j++)
               f = f * 10;
            a = a + t * f;
            n2 = n2/10;
        }
        
        
        if(a==x) return true;
          else return false;
        
    }
};
