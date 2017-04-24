class Solution
{
public:
    vector<vector<int> > fourSum(vector<int>& nums,int target)
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
     for(int j=0; j<len-1; j++)
     {
       int new_4 = nums.at(j);
       if(j>0 && nums.at(j-1)==new_4) continue; //1,1,1,1,target = 4
       
      for(int i=j+1; i<len-1; i++)
      {
        int x = nums.at(i);
        //-1,0,0,0
        if(i>j+1 && nums.at(i-1)==x) continue;  //去掉重复的,当然第一个不能去掉，例：0,0,0
        int tar = target-(x+new_4);

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
            res.push_back(new_4);
            res.push_back(x);
            res.push_back(y);
            res.push_back(z);
            vec.push_back(res);

            //int temp_l = left;
            //int temp_r = right;
            // left++;
            // right--;
            while(left+1<right && y==nums.at(left+1)) left++;   //第一个用过之后才能去掉,也就是有效
            while(right-1>left && z==nums.at(right-1)) right--;
            left++;
            right--;
          }
        }

      }
    }
    
      return vec;
    }
};

