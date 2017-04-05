

class Solution {
public:
    int reverse(int x) {
        int x2;
        int flag;
        if(x >= 0) {flag = 1; x2 = x;}
         else {flag = 0; x2 = -x;}
        
        int a[50];
        int cnt = 0;

        if(x == 0) return x;
/*
        while(x2)
        {
            a[cnt++] = x2%10;
            x2 = x2/10;
        }
        
        /////////134;
        /////   a[0]=4; a[1]=3; a[2]=1; cnt = 3;
        
        
        
    //    int ans = a[0];
        int ans = 0;
        for(int i=0; i<cnt; i++)
        {
            ans = ans*10 + a[i];
            
        }
*/
        int ans = 0;  
        while (x2 >= 1) 
        { //逐个地处理x的个位，十位，百位...  
            if ((ans != 0) && (INT_MAX / ans < 10))
            // || ((unsigned int)abs(num * 10) + (unsigned int)(x % 10) > INT_MAX)){//溢出  
                return 0;  
            //} 
            ans = ans*10 + (x2%10); //注意求个位可以用%，不用像上面那么麻烦。  
            x2 = x2 / 10;  
        }        
     //   if(ans<0) return 0;

     
        
        if(flag) return ans;
          else return -ans;
        
        
    }
};



/*
首先需要了解的是最大整数和负数，在limits.h中有宏定义，如下：

    #define INT_MAX 2147483647  
    #define INT_MIN (-INT_MAX - 1)  

对于本题的乘法判断溢出的方法为：


    //a*b是否溢出  
    (a&&b != 0) && (INT_MAX / abs(a) < b)  

对于加法是否溢出：

    //a+b是否溢出，注意a、b为非负整数  
    (unsigned int)a + (unsigned int)b > INT_MAX)  

*/
