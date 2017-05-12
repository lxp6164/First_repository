//老是要节省内存，好烦
class Solution
{
public:
    int removeDuplicates(vector<int>& nums) 
    {
        int len = nums.size();
        int cnt = 0;
        for(int i=0; i<len; i++)
        {
            if(i==0) {cnt++; continue;}
            //因为排序的缘故，直接修改就可以...666
            if(nums.at(i)!=nums.at(i-1))
            {
                nums.at(cnt++) = nums.at(i);
            }
        } 
        return cnt;
        /*原来还要改数组，，，英文的过
        //int len = nums.size();
        vector<int>::iterator iter1;
        vector<int>::iterator iter2;
        //iter = nums.begin();
        int cnt = 0;
        int flag = 0;
        for(iter1=nums.begin(); iter1!=nums.end(); iter1++)
        { 
          flag = 0;
          for(iter2=nums.begin(); iter2!=iter1; iter2++)    
          {
              if(*iter1==*iter2) {flag=1;break;}
          }
          if(!flag) cnt++;
        }
        return cnt;
        */
    }
};
