#include<iostream>
#include<string>
#include<cstring>
#include<algorithm>
using namespace std;

#define max1(a,b) a>b?a:b



class Solution
{
 public:
    int lengthOfLongestSubstring(string s)
    {
      int len = s.length();
      int i=0,j=0;
      int maxlen = 0;
      //这是映射表,记录某字符是否出现过
      bool exist[256]={false};

      while(j < len)
      {
         if(exist[s[j]])
         {
           maxlen = max1(maxlen,j-i);
           while(s[i]!=s[j])
           {
            exist[s[i]] = false;
            i++;
           }
           i++;
           j++;
        }else
         {
          exist[s[j]] = true;
          j++;
         }
      }
      maxlen = max1(maxlen,len-i);
      return maxlen;
    }

};




int main()
{
  string a;
  while(cin>>a)
  {
    //  cout<<a<<endl;
    Solution ss;
    cout<<ss.lengthOfLongestSubstring(a)<<endl;

  }




  return 0;
}
