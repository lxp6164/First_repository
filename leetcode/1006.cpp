#include<iostream>
#include<cstring>
#include<string>
#include<cmath>
using namespace std;


class Solution
{
  public:
    string convert(string s, int numRows)
    {
      if(numRows==1) return s;

      int len = s.size();
      // cout<<len<<endl;
      //  cout<<s[len-1]<<" x  "<<s[len]<<endl;
      //i==0

      int row;
      string res = "";
      // res += s[0];

      int i = 0;
      while(i<len){

        res += s[i];
        i +=((numRows-2)*2 + 2);
      }
      //  cout<<"xxx    "<<res<<endl;
      for(row=2; row<numRows; row++){
        i = row-1;
        res += s[i];
        while(i<len){
          // res += s[i];
          int t1 = (numRows-(row+1))*2+2;
          int t2 = (row-2)*2+2;
          if(i+t1<len){ i+=t1; res+=s[i];}
          else break;
          if(i+t2<len){ i+=t2; res+=s[i];}
          else break;

        }
      }
      i = numRows-1;

      while(i<len){
         res += s[i];
         i += (numRows-2)*2 + 2;
      }


      return res;
    }
};


int main()
{
  string str1,ans;
  int n;
  Solution A;
  while(cin>>str1>>n){
    ans = A.convert(str1,n);
    cout<<ans<<endl;

  }








}
