#include<iostream>
#include<memory.h>
#include<vector>
using namespace std;

class Solution
{
public:
    bool isValid(string s)
    {
        bool ans = true;
        int len = s.length();
        //bool flag[len+5];
        vector<bool> flag(len+5,false);
       // memset(flag,false,sizeof(flag));
        int x1=0,x2=0,x3=0,y1=0,y2=0,y3=0;
        for(int i=0; i<len; i++)
        {
            if(s.at(i)=='(') x1++;
            if(s.at(i)==')') y1++;
            if(s.at(i)=='[') x2++;
            if(s.at(i)==']') y2++;
            if(s.at(i)=='{') x3++;
            if(s.at(i)=='}') y3++;
        }
        if(x1!=y1 || x2!=y2 || x3!=y3) return false;
        //  cout<<"????"<<endl;

        for(int i=0; i<len; i++)
        {
           if(s.at(i)==')'||s.at(i)==']'||s.at(i)=='}')
             {  // cout<<"i = "<<i<<endl;

               for(int j=i-1; j>=0; j--)
                 {
                   if(flag.at(j)) continue;
                   if((s.at(j)=='('&&s.at(i)==')') || (s.at(j)=='['&&s.at(i)==']') ||(s.at(j)=='{'&&s.at(i)=='}'))
                     {//  cout<<i<<"            "<<j<<endl;
                       flag.at(i) = true;
                       flag.at(j) = true;
                       break;
                   }
                   else return false;

               }
           }

        }
        return ans;
    }
};

int main()
{
  string a;
  Solution S;
  while(cin>>a)
  {
    cout<<S.isValid(a)<<endl;



  }




  return 0;
}
