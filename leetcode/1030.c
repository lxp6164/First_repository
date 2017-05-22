#include<stdio.h>
#include<string.h>
//#include<memory.h>
#include<stdlib.h>

/*
//想不用stl,结果装逼失败
//我的,看错题了
int* findSubstring(char* s, char** words, int wordsSize, int* returnSize)
{
     int len_w;
     if(wordsSize>=1)//wordsSize鎵嶆槸鍗曡瘝涓暟???
        len_w=strlen(words[0]);
      else
        return NULL;
     int len_s = strlen(s);
     int cnt_w = len_w/wordsSize;

     int *ans = (int*)malloc(sizeof(int)*1000);

     //     int len_w = strlen(words[0]);


      printf("%d   %d     %d\n",len_s,len_w,cnt_w);

     // int cnt_h = 0;
     //int *hash = (int*)malloc(sizeof(int)*cnt_w);
     int count_h[cnt_w+5];
     int flag_h[cnt_w+5];
     memset(flag_h,0,sizeof(flag_h));
     memset(count_h,0,sizeof(count_h));

     for(int i=0; i<cnt_w; i++)
     {
       int cnt = 1;
       if(!flag_h[i])
       {
          for(int j=i+1; j<cnt_w; j++)
          {
            if(strcmp(words[i],words[j])==0) //鐩哥瓑
            {
              flag_h[j] = 1; //鍑虹幇杩囦簡
              cnt++;
            }

          }
          count_h[i] = cnt;
       }
     }

     int temp_cnt[cnt_w+5];
     for(int i=0; i<len_s-len_w*wordsSize; i++)
     {
       for(int pp=0; pp<cnt_w; pp++)
         temp_cnt[pp] = count_h[pp];

       for(int j=0; j<cnt_w; j++)
       {
         if(!flag_h[j])
         {



         }


       }


     }


     //ans[(*returnSize)++]=i;
return ans;
}



int main()
{
  char s1[10000];
  char* words1[10]={"123","456","789","123"};

  printf("1111\n");
  while(scanf("%s",s1))
  {
  printf("2222\n");
    int n,m;
    scanf("%d%d",&n,&m);

      printf("33333\n");
      // for(int i=0; i<n; i++)
      //   scanf("%s",words1[i]);

    findSubstring(s1,words1,m,0);
  }

return 0;
}
*/

//别人的

 int* findSubstring(char* s, char** words, int wordsSize, int* returnSize) {  
        int lenWord,lenS;  
        int flag2,flag3;  
        int *ans;  
        ans=(int *)malloc(sizeof(int)*1000);  
        if(wordsSize>=1)  
            lenWord=strlen(words[0]);  
        else  
            return NULL;  
        int i,j,m,n,l;  
        lenS=strlen(s);  
      
      
        int *flags,*flagsCount;  
        flags=(int *)malloc(sizeof(int)*wordsSize);  
        flagsCount=(int *)malloc(sizeof(int)*wordsSize);  
    //   for(i=0;i<wordsSize;i++) 
    //        flags[i]=0;
        for(i=0;i<wordsSize;i++)  
            flags[i]=1;  //当前单词算一个  
        //int *numWord;  //记录每个不重复单词在单词表中出现的词数  
        //记录每个单词从当前位置到末尾出现的次数，那么这个单词第一次出现的地方对应的次数就是这个单词总共出现的次数  
        for(i=0;i<wordsSize;i++)  
        {  
            for(j=i+1;j<wordsSize;j++)  
                if(strcmp(words[i],words[j])==0)  
                    flags[i]++;  
            flagsCount[i]=flags[i];  
        }  
      
      
      
        for(i=0;i<=(lenS-lenWord*wordsSize);i++)  
        {  
            for(l=0;l<wordsSize;l++)  
                flagsCount[l]=flags[l];  
            flag2=0;  
            for(j=0;j<wordsSize;j++)//向后检查wordsSize个单词  
            {  
                //flag1=0;  //第j个单词匹配失败  
                flag3=0;  //当前单词找不到匹配的单词  
                for(m=0;m<wordsSize;m++) //检查是否和单词组中的某个单词匹配  
                {  
                    for(n=0;n<lenWord;n++)  
                    {  
                        if(s[i+j*lenWord+n]==words[m][n])  
                            ;  
                        else  
                            break;  
                    }  
      
                    if(n==lenWord&&flagsCount[m]>0)   //当前单词匹配成功而且这个单词还没有减完  
                    {  
                        flag3=1;  
                        flagsCount[m]=flagsCount[m]-1;  
                        break;   //匹配成功了就不用再检查了  
                    }  
                    else if(n==lenWord&&flagsCount[m]==0)   //该单词不够了  
                    {  
                        flag2=1;  
                        break;  
                    }  
                }  
                if(m==wordsSize&&flag3==0)  //当前单词找不到一个匹配的单词  
                {  
                    break;  
                }  
                if(flag2==1)   //虽然匹配到该单词，但是该单词的个数不够了  
                {  
                    break;  
                }  
      
            }  
            if(j==wordsSize)  //全部匹配  
            {  
                ans[(*returnSize)++]=i;  
            }  
        }  
        return ans;  
      
    }  



