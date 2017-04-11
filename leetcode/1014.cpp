//找出所有字符串的最长公共前缀
//9ms

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) 
    {
        int len = strs.size();
        if(!len) return "";
        
        int len_min = strs.at(0).length();
        int flag_short = 0;
        for(int i=1; i<len; i++)
        {
            int temp = strs.at(i).length();
            if(len_min>temp){len_min = temp; flag_short = i;}
        }
        string str = strs.at(flag_short);
      //  strcpy(str,strs.at(flag_short));
        

        for(int i=0; i<len; i++)
        {   int cnt = 0;
            int len_temp = strs.at(i).length();
            for(int j=0; j<len_min; j++)
            {
                if(str.at(j)==strs.at(i).at(j)){cnt++;}
                else break;
            }
         //   if(cnt==0)
            
            if(cnt<len_min)
            {
                str = str.substr(0,cnt);
                len_min = cnt;
            }
        }
        return str;
    }
};
