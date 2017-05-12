#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val)
    {
        int cnt = 0;
        int len = nums.size();

        for(int i=0; i<len; i++)
          {

            if(nums[i]!=val)
              {// cout<<nums[i]<<"   "<<val<<endl;
                nums[cnt++]=nums[i];

              }
          }
        return cnt;

    }
    };


  int main()
  {
    vector<int> a;
    int val;
    int n;
    while(cin>>n)
    {
      cin>>val;
      int x;
      for(int i=0; i<n; i++)
      {
        cin>>x;
        a.push_back(x);
      }
        Solution S;
        int ans = S.removeElement(a,val);

        cout<<ans<<endl;


    }



    return 0;
  }
