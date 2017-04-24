#pragma GCC diagnostic error "-std=c++11" //支持c++11新特性
#include<iostream>
#include<string>
#include<cstring>
#include<vector>
#include<cmath>
#include<algorithm>
using namespace std;

class Solution
{
public:
    vector<vector<int> > threeSum(vector<int>& nums)
    {
      vector<vector<int> > vec;
      sort(nums.begin(),nums.end());
      /*
      vector<int> res;
      res.push_back(nums.at(0));
      res.push_back(nums.at(1));
      res.push_back(nums.at(2));
      //res.push_back(vector<int>{sortedNum[start-1], sortedNum[head], sortedNum[tail]});
      vec.push_back(res);
     */
      int len = nums.size();
      for(int i=0; i<len-1; i++)   //i<len-2 即可
      {
        int x = nums.at(i);
        //-1,0,0,0
        if(i>0 && nums.at(i-1)==x) continue;  //去掉重复的,当然第一个不能去掉，例：0,0,0
        int tar = -x;

        int left = i+1;
        int right = len-1;
        while(left<right)
        {
          int y = nums.at(left);
          //  if(left+1<len-1 && y==nums.at(left+1))
          int z = nums.at(right);
          //   cout<<x<<"  "<<y<<"  "<<z<<endl;
          if(y+z < tar){left++; continue;}
          if(y+z > tar){right--; continue;}

          if(y+z==tar)
          {
            vector<int> res;
            res.push_back(x);
            res.push_back(y);
            res.push_back(z);
            vec.push_back(res);

            // int temp_l = left;
            //  int temp_r = right;
            // left++;
            // right--;
            // cout<<left<<" 111111  "<<right<<endl;
            while(left+1<right && y==nums.at(left+1)) left++;   //第一个用过之后才能去掉,也就是有效
            while(right-1>left && z==nums.at(right-1)) right--;
            // if(left==temp_l) left++;
            // if(right==temp_r) right--;
            //cout<<left<<" 222222   "<<right<<endl;
            left++;
            right--;
           }
         }

       }

      return vec;
     }
 };


int main()
{
  vector<int> a;
  int n;
  Solution S;
  while(cin>>n)
    {
      int x;
      for(int i=0; i<n; i++)
      {   cin>>x;
          a.push_back(x);
      }

      vector<vector<int> > vec;
      cout<<"!!!!"<<endl;
      vec = S.threeSum(a);
      cout<<"?????"<<endl;




      vector<vector<int> >::iterator iter1;
      for(iter1=vec.begin(); iter1!=vec.end(); iter1++)
      {
        vector<int>::iterator iter2;
        for(iter2=iter1->begin(); iter2!=iter1->end(); iter2++)
          cout<<*iter2<<endl;

      }


    }




  return 0;
}
