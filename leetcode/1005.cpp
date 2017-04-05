#include<iostream>
#include<cstring>
#include<string>
#include<cmath>
#include<algorithm>
using namespace std;


class Solution
{
   public:
   string longestPalindrome(string s)
   {
     string t = "$#"; //最前面加个$防止越界;最后默认以＇\0＇结尾，无需再加
     int len = s.size();
     for(int i=0; i!=len; i++){
       t += s[i];
       t += '#';
     }

     int len2 = t.size();
     int p[len2+10]={0};
     // memset(p,sizeof(p),0);

     int id=0,mx=0,resid=0,resmx=0;
     //求Ｐ［i］，也就是回文串半径
     for(int i=0; i!=len2; i++){
       //核心，利用之前求过的来快速求p[i]的基础值
       if(mx > i) p[i] = min(p[2*id-i],mx-i);
       else p[i] = 1;

      //再向左右两边扩展
       while(t[i+p[i]] == t[i-p[i]])
         p[i]++;

       ////////////////////////////
       //更新最长回文串最右值和中心
       if(mx < i+p[i]){mx = i+p[i]; id = i;}

       //更新最终结果
       if(resmx <p[i]){resmx=p[i]; resid=i;}

     }
     //substr是C++语言函数，主要功能是复制子字符串，要求从指定位置开始，并具有指定的长度。
       return s.substr((resid-resmx)/2,resmx-1);
       //加上#号后，长度变为两倍，故要除以2
       //实际字符串长度只有p[i]-1
       //实际测试，若长度相同则输出前面的
   }




};



int main()
{
  string str;
  string ans;
  Solution A;
  while(cin>>str){
    ans = A.longestPalindrome(str);
    cout<<ans<<endl;
    //  cout<<"oh"<<endl;
  }





  return 0;
}
