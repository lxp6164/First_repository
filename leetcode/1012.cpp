/*
【罗马数字】

1~9: {"I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"};

10~90: {"X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"};

100~900: {"C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"};

1000~3000: {"M", "MM", "MMM"}.


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

 string zhuanhuan(int flag)
 {
      string s = "";
      switch (flag)
        {  
            case 1: s +='I';break;
            case 5: s +='V';break;
            case 10: s +='X';break;
            case 50: s +='L';break;
            case 100: s +='C';break;
            case 500: s +='D';break;
            case 1000: s +='M';break;
        }  
 return s;
 }
 
    string intToRoman(int num)
    {
      string str = "";
      
      int flag = 1000;
      while(num)
      {
        while(num>=flag)    
        {
          str += zhuanhuan(flag);
          num -=flag;
        }
        if(num>=(flag-flag/10)){str+=zhuanhuan(flag/10);str+=zhuanhuan(flag);num-=(flag-flag/10);}
        if(num>=(flag/2)){str+=zhuanhuan(flag/2); num-=(flag/2);}
        if(num>=(flag/2-flag/10)) {str+=zhuanhuan(flag/10); str+=zhuanhuan(flag/2); num-=(flag/2-flag/10);}
        
        flag /= 10;
      }      
    return str;  
    }
};





