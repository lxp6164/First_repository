#include<iostream>
#include<vector>
#include<map>
#include<string>
using namespace std;


class Solution
{
  public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        map<int,int> map1;
        vector<int> res;

        int n = nums.size();
       // cout<<"n=    "<<n<<endl;
        for(int i=0; i<n; i++)
             map1[nums[i]] = i;

        for(int i=0; i<n; i++)
        {
            int t = target - nums[i];
            //查找另一个mao里
            map<int,int>::iterator iter = map1.find(t);
            if(iter != map1.end() && iter->second != i)//存在另一个数，且不为自身
            {

                res.push_back(i);
                res.push_back(iter->second);
                return res;
            }

        }

    }

};







/*
std::map<X, Y>实际储存了一串std::pair<const X, Y>
std::map<std::string, int> m = /* fill it
auto it = m.begin();

这里，如果你用*it，那么你将得到map第一个元素的std::pair：
现在你可以接收std::pair的两个元素：
(*it).first会得到key，
(*it).second会得到value。
*/

/*
使用count，返回的是被查找元素的个数。如果有，返回1；否则，返回0。注意，
map中不存在相同元素，所以返回值只能是1或0。

使用find，返回的是被查找元素的位置，没有则返回map.end()。
*/

int main()
{
    int n;
    int x;
    vector<int> a;
    int T;
    cin>>T;


         for(int i=0; i<T; i++)
         {
             cin>>n;
             a.push_back(n);

         }
         cin>>x;
/*
         vector<int>::iterator iter;
         vector<int>::iterator begin1;
         vector<int>::iterator end1;
         begin1 = a.begin();
         end1 = a.end();
         for(iter=begin1; iter!=end1; iter++)
                cout<<*iter<<endl;

*/
//cout<<"???"<<endl;


         vector<int>::iterator it;
         for(it=a.begin(); it!=a.end(); it++)
         cout<<*it<<"  ";
         cout<<endl;

         vector<int> ans;
       //  ans = Solution::twoSum(a,x);
         Solution solu;// =  Solution();
         ans = solu.twoSum(a,x);

         vector<int>::iterator it2;
         for(it2=ans.begin(); it2!=ans.end(); it2++)
         cout<<*it2<<"  ";
         cout<<endl;

}
