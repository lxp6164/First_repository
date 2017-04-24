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
    int threeSumClosest(vector<int>& nums, int target)
    {
      sort(nums.begin(),nums.end());
      int len = nums.size();
      int ans = nums.at(0) + nums.at(1) + nums.at(2);
      int chaju = abs(ans - target);


      for(int i=0; i<len-1; i++)
      {
        int x = nums.at(i);

        int left = i+1;
        int right = len-1;
        while(left<right)
        {
          int y = nums.at(left);
          //  if(left+1<len-1 && y==nums.at(left+1))
          int z = nums.at(right);
          //   cout<<x<<"  "<<y<<"  "<<z<<endl;
          int sum = x + y + z;
          int temp = abs(sum-target);
          if(temp<chaju)
          {
            chaju = temp;
            ans = sum;
          }
          if(sum==target) return target;
          if(sum<target) left++;
          else right--;


       }
      }

      return ans;
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
      int tar;
      cin>>tar;
      vector<vector<int> > vec;
      cout<<"!!!!"<<endl;
      int ans = S.threeSumClosest(a,tar);
      cout<<"?????"<<endl;
      cout<<ans<<endl;



    }

  return 0;
}
