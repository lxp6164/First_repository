#include<iostream>
#include<vector>
using namespace std;


class Solution
{
  public:
  double findMedianSortedArrays(vector<int> &num1, vector<int> &num2)
  {
    // double result;
    vector<int>::iterator iter1_bg,iter1_ed,iter2_bg,iter2_ed;

    //for(iter1=num1.begin(); iter1!=num1.end(); iter1++)
    // {
    // cout<<*iter1<<endl;
    //}
    iter1_bg = num1.begin(); iter1_ed = num1.end();
    iter2_bg = num2.begin(); iter2_ed = num2.end();
    // 1 2 3 4 5 6
    //1 2 3 4 5
    int len1 = num1.size();
    int len2 = num2.size();
      int len = len1 + len2;
    bool flag;
    if((len&1)) flag = true;
    else flag = false;
    //cout<<len<<endl;

    int temp[len/2 + 10];
    int zhongjian = len/2 + 1;
    int cnt = 0;
    while(iter1_bg!=iter1_ed && iter2_bg!=iter2_ed){
      if(*iter1_bg <= *iter2_bg){
        temp[cnt++] = *iter1_bg;
        //  cout<<temp[cnt-1]<<endl;
        iter1_bg++;
      }else{
        temp[cnt++] = *iter2_bg;
        iter2_bg++;
      }
      if(cnt == zhongjian) {//return
        if(flag) return temp[cnt-1];
        else return (double)(temp[cnt-1] + temp[cnt-2])/2.0;
      }
    }

    while(iter1_bg != iter1_ed){
      temp[cnt++] = *iter1_bg;
      if(cnt == zhongjian) {//return
        if(flag) return temp[cnt-1];
        else return (double)(temp[cnt-1] + temp[cnt-2])/2.0;
      }
      iter1_bg++;
    }
    while(iter2_bg != iter2_ed){
      temp[cnt++] = *iter2_bg;
      if(cnt == zhongjian) {//return
        if(flag) return temp[cnt-1];
        else return (double)(temp[cnt-1] + temp[cnt-2])/2.0;
      }
      iter2_bg++;
    }


  }

};





int main()
{
  vector<int> vct1;
  vector<int> vct2;
  int n,m;
  while(cin>>n>>m){
    int x;
    for(int i=0; i<n; i++){
      cin>>x;
      vct1.push_back(x);
    }
    for(int j=0; j<m; j++){
      cin>>x;
      vct2.push_back(x);
    }
    Solution ret;
    double ans = ret.findMedianSortedArrays(vct1,vct2);
    cout<<ans<<endl;
  }



  return 0;
}
