class Solution {
public:
    int strStr(string haystack, string needle)
    {
        /*熟练stl的解法...
        //1.
        int ans = haystack.find(needle);  
        return (ans==string::npos) ? -1 : ans;  
        //
        //2.
        if(haystack.empty()&&needle.empty())  
        return 0;  
        string::iterator it=search(haystack.begin(),haystack.end(),needle.begin(),needle.end());  
        return it==haystack.end()?-1:it-haystack.begin(); 
        */
        
        //强撸
        if(needle=="") return 0;
        if(haystack==needle) return 0;
       // int ans = -1;
        int len1 = haystack.length();
        int len2 = needle.length();
        if(len1<len2) return -1;
        
        //int cnt = 0;
        //dp更快哦，但是我随便写个简单的吧
        for(int i=0; i<len1; i++)
        {
            
            if(i+len2<=len1 && haystack.at(i)==needle.at(0))
            {
               int cnt = 0;
               int flag = 0;
               for(int j=1; j<len2; j++)
               {
                   if(!cnt && haystack.at(i+j)==haystack.at(i)) cnt = j;
                   if(haystack.at(i+j) != needle.at(j))
                   {
                       if(cnt) i += (cnt-1);
                       else i += (j-1);
                      
                       flag = 1;
                       break;
                   }
                   
                   
               }
               if(!flag) return i;
               
            }
            
        }
        
        
        return -1;
        
    }
};
