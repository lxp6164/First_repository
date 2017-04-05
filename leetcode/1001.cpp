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
            //������һ��mao��
            map<int,int>::iterator iter = map1.find(t);
            if(iter != map1.end() && iter->second != i)//������һ�������Ҳ�Ϊ����
            {

                res.push_back(i);
                res.push_back(iter->second);
                return res;
            }

        }

    }

};







/*
std::map<X, Y>ʵ�ʴ�����һ��std::pair<const X, Y>
std::map<std::string, int> m = /* fill it
auto it = m.begin();

����������*it����ô�㽫�õ�map��һ��Ԫ�ص�std::pair��
��������Խ���std::pair������Ԫ�أ�
(*it).first��õ�key��
(*it).second��õ�value��
*/

/*
ʹ��count�����ص��Ǳ�����Ԫ�صĸ���������У�����1�����򣬷���0��ע�⣬
map�в�������ͬԪ�أ����Է���ֵֻ����1��0��

ʹ��find�����ص��Ǳ�����Ԫ�ص�λ�ã�û���򷵻�map.end()��
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
