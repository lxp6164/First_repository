/*
 * 问题：将字符窜转换成数字
 *分析：感觉题目不难，但是细节很多，容易想不到
 *1.数字前面有空格 如s=“    123456”
 *2.数字前出现了不必要或多于的字符导致数字认证错误，输出0   如s=“   b1234”  ，s=“  ++1233” , s=“ +-1121”  s="  - 123"
 *3.数字中出现了不必要的字符，返回字符前的数字 如s=“   12a12” ， s=“ 123  123”
 *4.数字越界 超过了范围（-2147483648--2147483647) 若超过了负数的 输出-2147483648  超过了正数的输出2147483647
 *在科普一个知识点，倘若某个数超过了2147483647则会变为负数，反过来一样
 */

#include<iostream>
#include<cstring>
#include<string>
#include<cmath>
#include<climits>
using namespace std;



class Solution
{
public:
    int myAtoi(string str)
    {
      const long long maxn = 999999999999;
      long long temp = maxn;
      // int ans = 0 ;

      int cnt_char = 0; //记录非数字字符个数
      int flag_fh = 1;  //1为正数,-1为负数
      //int cnt_str = 0;
      int len_str = str.size();
      for(int i=0; i!=len_str; i++){
        if(str[i]==' '){
          if(cnt_char > 0) break;
          if(temp == maxn) continue;
          else return (int)temp*flag_fh;
        }

        if(str[i]!=' ' &&str[i]<'0' || str[i]>'9'){
          if(temp != maxn) return (int)temp*flag_fh;
          else{
            if(cnt_char < 1){
            if(str[i]=='+' || str[i]=='-'){
              if(str[i]=='+') flag_fh = 1;
              else flag_fh = -1;
              ++cnt_char;
              }
            else return 0;
            }
            else return 0;
          }
          continue;
        }
        if(str[i]<='9' && str[i]>='0'){
           if(temp==maxn) temp = str[i] - '0';
           else temp = temp*10 + (str[i] - '0');
        }
        if(flag_fh==1 && flag_fh*temp>INT_MAX) return INT_MAX;
        if(flag_fh==-1 && flag_fh*temp<(long long)INT_MIN) return INT_MIN;

     }
    if(temp==maxn) return 0;
    else return (int)temp*flag_fh;
   }
};



int main()
{
  Solution S;
  string str;
  while(cin>>str){
    cout<<S.myAtoi(str)<<endl;
//cout<<INT_MIN<<endl;
  }

  return 0;
}
