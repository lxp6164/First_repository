#include<stdio.h>
#include<string.h>
//#include<memory.h>
#include<stdlib.h>

/*
//�벻��stl,���װ��ʧ��
//�ҵ�,��������
int* findSubstring(char* s, char** words, int wordsSize, int* returnSize)
{
     int len_w;
     if(wordsSize>=1)//wordsSize才是单词个数???
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
            if(strcmp(words[i],words[j])==0) //相等
            {
              flag_h[j] = 1; //出现过了
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

//���˵�

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
            flags[i]=1;  //��ǰ������һ��  
        //int *numWord;  //��¼ÿ�����ظ������ڵ��ʱ��г��ֵĴ���  
        //��¼ÿ�����ʴӵ�ǰλ�õ�ĩβ���ֵĴ�������ô������ʵ�һ�γ��ֵĵط���Ӧ�Ĵ���������������ܹ����ֵĴ���  
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
            for(j=0;j<wordsSize;j++)//�����wordsSize������  
            {  
                //flag1=0;  //��j������ƥ��ʧ��  
                flag3=0;  //��ǰ�����Ҳ���ƥ��ĵ���  
                for(m=0;m<wordsSize;m++) //����Ƿ�͵������е�ĳ������ƥ��  
                {  
                    for(n=0;n<lenWord;n++)  
                    {  
                        if(s[i+j*lenWord+n]==words[m][n])  
                            ;  
                        else  
                            break;  
                    }  
      
                    if(n==lenWord&&flagsCount[m]>0)   //��ǰ����ƥ��ɹ�����������ʻ�û�м���  
                    {  
                        flag3=1;  
                        flagsCount[m]=flagsCount[m]-1;  
                        break;   //ƥ��ɹ��˾Ͳ����ټ����  
                    }  
                    else if(n==lenWord&&flagsCount[m]==0)   //�õ��ʲ�����  
                    {  
                        flag2=1;  
                        break;  
                    }  
                }  
                if(m==wordsSize&&flag3==0)  //��ǰ�����Ҳ���һ��ƥ��ĵ���  
                {  
                    break;  
                }  
                if(flag2==1)   //��Ȼƥ�䵽�õ��ʣ����Ǹõ��ʵĸ���������  
                {  
                    break;  
                }  
      
            }  
            if(j==wordsSize)  //ȫ��ƥ��  
            {  
                ans[(*returnSize)++]=i;  
            }  
        }  
        return ans;  
      
    }  



