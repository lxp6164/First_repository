/*
        switch (ch)
        {  
            case 'I': return 1;  //
            case 'V': return 5;  
            case 'X': return 10;  //
            case 'L': return 50;  
            case 'C': return 100;  //
            case 'D': return 500;  
            case 'M': return 1000;  //
        }  

*/



class Solution {
public:

    int zhuanhuan(char ch)
    {
       switch (ch)
        {  
            case 'I': return 1;  //
            case 'V': return 5;  
            case 'X': return 10;  //
            case 'L': return 50;  
            case 'C': return 100;  //
            case 'D': return 500;  
            case 'M': return 1000;  //
        }  
    }


    int romanToInt(string s)
    {
        int ans = 0;
        int len = s.size();
        for(int i=0; i<len; i++)
        {
            int x = zhuanhuan(s.at(i));
            int y = -1;
            if(i+1<len) y = zhuanhuan(s.at(i+1));
            if((i+1<len) && x<y)
            {
                ans += (y - x);
                i++;
                continue;
            }
            ans += x;
        }
        
     return ans;
    }
};
