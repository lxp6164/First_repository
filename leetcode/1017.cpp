#include<iostream>
#include<string>
#include<vector>
using namespace std;

class Solution
{
public:
  vector<string> ans;
  string all_str = "";
  void dfs(string digits,int cnt,int len_digits)
  {//cout<<digits<<"   "<<cnt<<"   "<<len_digits<<endl;
    if(cnt == len_digits)
    {
      if(all_str!="")
        ans.push_back(all_str);
       //cout<<all_str<<endl;
      return;
    }
    char ch = digits.at(0);
    // cout<<ch<<endl;
    string s = "";
    switch(ch)
    {
      case '0':break;
      case '1':break;
      case '2':s+="abc"; break;
      case '3':s+="def"; break;
      case '4':s+="ghi"; break;
      case '5':s+="jkl"; break;
      case '6':s+="mno"; break;
      case '7':s+="pqrs"; break;
      case '8':s+="tuv"; break;
      case '9':s+="wxyz"; break;
    }

    int len_s = s.length();
    // cout<<"len_s   "<<len_s<<endl;
    // cout<<endl;

    //cout<<"cnt+1 =  "<<cnt+1<<endl;
    //cout<<"len_digits = "<<len_digits<<endl;
    //  cout<<"digits.len = "<<digits.length()-1<<endl;

    //cout<<"digits = "<<digits;
    //digits变了，没有注意．．.
    string dig_temp = "";
    if(cnt+1 != len_digits) dig_temp = digits.substr(1,digits.length()-1);

    //cout<<endl;
    // cout<<"dig_temp !!!  "<<dig_temp<<endl;


    if(ch=='0'||ch=='1')
    {
       dfs(dig_temp,cnt+1,len_digits);
       return;

    }

    for(int i=0; i<len_s; i++)
    {
      //+
      all_str += s.at(i);
      dfs(dig_temp,cnt+1,len_digits);
      //--
      all_str = all_str.substr(0,all_str.length()-1);
    }

  }

  vector<string> letterCombinations(string digits)
  {
    int len_digits = digits.length();
    dfs(digits,0,len_digits);
    return ans;
  }
};


int main()
{

  string str;
  Solution S;
  while(cin>>str)
  {
    S.letterCombinations(str);

    //string sss = "34";

    //cout<<
  }



  return 0;
}
