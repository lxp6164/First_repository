#pragma GCC diagnostic error "-std=c++11" //支持c++11新特性
#include<iostream>
#include<string>
#include<cstring>
using namespace std;

class Solution
{
public:
    bool isMatch(string s, string p)
    {
       int len_s = s.size();
       int len_p = p.size();

       if(s=="")
       { if(p=="") return true;
        int cnt_1 = 0;
        /////////////////////////////
        int flag_1 = 1;//1为有  //初始值设为0更好
        for(int r=0; r!=len_p; r++)
        {
         if(p.at(r)!='*') cnt_1++;
         else cnt_1--;  //if(p.at(n)=='*' && p.at(n-1)!='*')
         if(cnt_1<=0) cnt_1 = 0;
         //无c*d*型前缀
         if(cnt_1 > 1) {flag_1 = 0; break;}
         //   cout<<"cnt    "<<cnt_front<<endl;
        }
        if(cnt_1>=1) flag_1 = 0; //没有＊＊前缀或前缀不可去除 //&&flag_front==1???
        //flag==1在哪？？？？
        if(flag_1) return true;
        else return false;
       }
       else
       {
           if(p=="") return false;
       }



      // //ab c*d**ab
      // //ab c*d*a*b*ab
      // //方法:去掉p前面的...还不好去掉．．．靠
      // //来，丧心病狂递归一波

      // //   int len_preal = p.size();
      // // for()
      // //   int len_s = s.size();
      // //  int len_p = p.size();

       int len_front=0;
       int cnt_front = 0;
       int flag_front = 0;//1为有  //初始值设为0更好
       for(int n=0; n!=len_p; n++)
       { //每次遇到a,break，递归
         if(cnt_front==0 && (p.at(n)==s.at(0) || p.at(n)=='.'))
           { if(n!=0) {flag_front=1; len_front = n; break;}//有问题　a a* 死循环了
             // if(n==0){;}

           }
         if(p.at(n)!='*') cnt_front++;
         else cnt_front--;  //if(p.at(n)=='*' && p.at(n-1)!='*')
         if(cnt_front<=0) cnt_front = 0;
         //无c*d*型前缀
         if(cnt_front > 1) {flag_front = 0; break;}
         //   cout<<"cnt    "<<cnt_front<<endl;
       }
       if(cnt_front>=1) flag_front = 0; //没有＊＊前缀或前缀不可去除 //&&flag_front==1???
       cout<<"xxxcxc   "<<cnt_front<<"      "<<flag_front<<endl;
       //有** 前缀
       if(flag_front){
         //拷贝后面的到一个新string
         string p2 = p.substr(len_front,len_p-len_front); //+1? -1?
         cout<<"p2   "<<p2<<endl;
         bool res = isMatch(s, p2);
         cout<<"res    "<<res<<endl;
         if(res) return true;
       }





       ////////////////////////////////////////////
       //      int len_s = s.size();
       //int len_p = p.size();

       int dp[len_s+5][len_p+5] = {0};

       //从题意来说第一个不会是*
       if(s.at(0)==p.at(0) || p.at(0)=='.') dp[0][0] = 1;
       else return false;
       //


           cout<<"111"<<endl;
       //
       for(int j=1; j!=len_p; j++)
       {
         dp[0][j] = (dp[0][j-1] && (p.at(j)=='*'));
       }
       for(int m=0; m!=len_p-1; m++)   //if(0==len_s-1 && dp[0][m] && m+2<=len_p-1)
       { //if(0+2<=len_p-1)
         if(0==len_s-1 && dp[0][m] && m+2<=len_p-1)
         { //a a*b*c*
           cout<<"m=  "<<m<<endl;
          int flag = 1;
          int k;
          for(k=m+2; k<=len_p-1; k+=2)
            {    // cout<<k<<"    "<<p.at(k)<<"   d"<<endl;
              if(p.at(k)!='*')  {flag = 0; break;} //{flag = 0; break;}
            }

          if(p.at(len_p-1)=='*' && flag) return true;
         }
       }
      /////////////////////////////////////////////////////////////
      //ab c*ab

      for(int i=1; i!=len_s; i++)
        dp[i][0] = 0;  //

      cout<<"???????????"<<endl;

      int flag_use[len_p+5]={0};
      for(int i=1; i!=len_s; i++)
        for(int j=1; j!=len_p; j++)
        {
          if(p.at(j)!='.' && p.at(j)!='*')
            dp[i][j] = (dp[i-1][j-1] && (s.at(i)==p.at(j)));

          if(p.at(j)=='.')
            dp[i][j] = dp[i-1][j-1];
          if(p.at(j)=='*')
          { //*替代１次
            int a = (dp[i-1][j-1] && (s.at(i)==p.at(j-1) || p.at(j-1)=='.'));
            //*替代多次
            int b =(dp[i-1][j] && (s.at(i)==p.at(j-1) || p.at(j-1)=='.'));
        //  //*替代0次（*多余）
            int c =(dp[i][j-1] && (s.at(i)==p.at(j-1) ||p.at(j-1)=='.'));
            dp[i][j] = (a || b || c);

          }

          //前面可能不止一个＊，惨了．．．总之就是搞定e了前面可去掉类型，后面可去掉类型，现在还要搞中间可去掉类型是吧．．．
          int flag_pzj = 0;//中间
          int temp[len_p+5];
          //int yihuo[len_p+5];
          int cnt_temp = 0;
          // int cnt_yihuo = 0;
          for(int h=0; h!=len_p; h++) //从下标1开始
            if(dp[i-1][h]) temp[cnt_temp++] = h;//flag_pzj = h;
          //  cout<<"falg_pzj   "<<i<<" "<<j<<"    "<<flag_pzj<<endl;

          //某次去掉为1就行
         for(int tt=0; tt<cnt_temp; tt++)
         {
          flag_pzj = temp[tt];
          //如果从flag_pzj+1到j-1是可去掉的
          int flag_zhongjian = 1; //1为可去
          int cnt_zhongjian = 0;
          if(flag_pzj+1<j)
          {
           for(int g=flag_pzj+1; g<j; g++)
             {
             if(p.at(g)!='*') cnt_zhongjian++;
             else cnt_zhongjian--;

             if(cnt_zhongjian<=0) cnt_zhongjian = 0;
             if(cnt_zhongjian > 1) {flag_zhongjian = 0; break;}
             }
          if(cnt_zhongjian>=1) flag_zhongjian = 0;
          }
          else flag_zhongjian = 0;

          //中间可去
          if(flag_zhongjian)
            {cout<<"asdfghjk   "<<flag_pzj<<"   "<<j<<endl;
            int count = j-flag_pzj;
              if(p.at(j)!='.' && p.at(j)!='*')
              dp[i][j] = (dp[i-1][j-count] && (s.at(i)==p.at(j)));

              if(p.at(j)=='.') dp[i][j] = dp[i-1][j-count];
              if(p.at(j)=='*')
              { //*替代１次
                 int a = (dp[i-1][j-count] && (s.at(i)==p.at(j-count) || p.at(j-count)=='.'));
                 //*替代多次
                 int b =(dp[i-1][j] && (s.at(i)==p.at(j-count) || p.at(j-count)=='.'));
                 //  //*替代0次（*多余）
                 int c =(dp[i][j-count] && (s.at(i)==p.at(j-count) ||p.at(j-count)=='.'));
                 //dp[i][j] = (a || b || c);
                 dp[i][j] = (dp[i][j] || (a||b||c));
              }

          }
         }
         //for(int tt2=0; tt2<cnt_yihuo; tt2++)

          /*
            if(j>=3 && dp[i][j] == 0 && p.at(j-1)=='*')
              {
              if(p.at(j)!='.' && p.at(j)!='*')
              dp[i][j] = (dp[i-1][j-3] && (s.at(i)==p.at(j)));

              if(p.at(j)=='.') dp[i][j] = dp[i-1][j-3];
              if(p.at(j)=='*')
              { //*替代１次
                 int a = (dp[i-1][j-3] && (s.at(i)==p.at(j-3) || p.at(j-3)=='.'));
                 //*替代多次
                 int b =(dp[i-1][j] && (s.at(i)==p.at(j-3) || p.at(j-3)=='.'));
                 //  //*替代0次（*多余）
                 int c =(dp[i][j-3] && (s.at(i)==p.at(j-3) ||p.at(j-3)=='.'));
                 dp[i][j] = (a || b || c);
              }

             }
          */


          //case: ab abc*

             if(i==len_s-1 && dp[i][j] && j+2<=len_p-1)
             {
               cout<<i<<"    "<<j<<"   "<<dp[i][j]<<"   d2"<<endl;

               int flag = 1;
               ///////还是有些不对
               int k;
               for(k=j+2; k<=len_p-1; k+=2)
                 if(p.at(k)!='*') {flag = 0;break;}

               //  if(k==len_p-1 && flag)return true;　/////
               if(p.at(len_p-1)=='*' && flag) return true;
             }

             //  cout<<1<<endl;
        }

      for(int i=0; i!=len_s; i++)
        {  for(int j=0; j!=len_p; j++)
            cout<<dp[i][j]<<"  ";
          cout<<endl;
        }


      return dp[len_s-1][len_p-1];

    }
};



int main()
{
  string str1,str2;
  while(cin>>str1>>str2)
  {
    // int len = str.size();
    Solution S;
    cout<<S.isMatch(str1,str2)<<endl;
  }


  return 0;
}
