#include<stdio.h>
#include<math.h>
#include<limits.h>
#include<stdlib.h>

int divide(int dividend, int divisor)
{
    //if(dividend==-2147483648 && divisor==-1) return INT_MAX;
    if(!divisor) return INT_MAX;
    if(!dividend) return 0;

    int flag = 1;
    if((dividend>0&&divisor<0)||(dividend<0&&divisor>0)) flag = -1; 
    
    long long a;
    if(dividend==-2147483648) a = 2147483648;
     else a = abs(dividend); //int转long long不支持abs(-2147483648) = 2147483648;
    
    long long int b;
    if(divisor==-2147483648) b = 2147483648;
     else b = abs(divisor);

    //if(a<b) return 0;
   // printf("%lld   %lld\n",a,b);    

    long long int cnt = 0;
    while(a>=b)
    {/*超时
      * cnt++;
      * dividend -= divisor;
     */
   // printf("%lld   %lld\n",a,b);  
        //用位运算加速
        long long int temp = b;
        for(long long int i=0; (temp<<i)<=a; i++)
        {
            a -= (temp<<i);
            cnt += (1<<i);
            
        }
        
      
    }
   // printf("%lld\n",cnt);
    if(flag==1&&cnt>INT_MAX) return INT_MAX;
    return cnt*flag;
}

int main()
{
   int n,m;
   while(scanf("%d%d",&n,&m))
   { 

      int ans = divide(n,m);
      printf("%d\n",ans);
   }
return 0;
}
