/*
*最大盛水量取决于两边中较短的那条边，而且如果将较短的边换为更短边的话，盛水量只会变少。所以我们可以用两个头尾指针，计算出*当前最大的盛水量后，将较短的边向中间移，因为我们想看看能不能把较短的边换长一点。这样一直计算到左边大于右边为止就行了。
*/
//O(n) 19 ms

class Solution {
public:
    int maxArea(vector<int>& height) {
        int ans = 0;
        
        int len = height.size();
        int bg = 0;
        int ed = len-1;
        
        while(bg<ed)
        {
            int flag_min;
            if(height.at(bg)<height.at(ed)) flag_min = height.at(bg);
            else flag_min = height.at(ed);
            int temp = flag_min * (ed-bg);
            if(temp>ans) ans = temp;
            
            if(flag_min==height.at(bg)) bg++;
            else ed--;
            
            
        }
        return ans;
    }
};



/*
//Runtime: 538 ms
class Solution {
public:
    int maxArea(vector<int>& height) {
        int ans = 0;
        
        int len = height.size();
        for(int i=0; i<len; i++)
        {  
           //int x = height.at(i);
           int bg = 0;
           int ed = len-1;
           
           while(bg<len) 
           { 
               if(bg+1<len && height.at(bg)<height.at(i)) bg++;
               else break;
           }
           while(ed>=0) 
           { 
               if(ed-1>=0 && height.at(ed)<height.at(i)) ed--;
               else break;
           }
           //while(ed+1<len && height.at(ed+1)>=height.at(i)) ed++;
           
           int temp = (ed-bg)*height.at(i);
           if(temp>ans) ans = temp;
        
        }
        return ans;
    }
};

*/
