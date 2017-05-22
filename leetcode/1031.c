#include<stdio.h>


void nextPermutation(int* nums, int numsSize)
{
    int flag_index = -1;

    
    for(int i=numsSize-1; i>=1; i--)
    {
        if(nums[i]>nums[i-1]) {flag_index = i-1; break;}
        
    }
    

    
    if(flag_index!=-1)
    {   
        //比nums[flag_index]大，但在这些数里面最小的值
        int min_ed = numsSize-1;
        for(int i=numsSize-1; i>flag_index; i--)
          if(nums[i]>nums[flag_index]){min_ed=i; break;}
        
        
        printf("%d   %d\n",flag_index,min_ed);
        //int temp = nums[];
        nums[flag_index] = nums[flag_index]^nums[min_ed];
        nums[min_ed] = nums[flag_index]^nums[min_ed];
        nums[flag_index] = nums[flag_index]^nums[min_ed];
        
        //对min_ed+1--numsSize-1变为升序
        int len = numsSize-flag_index-1;
        for(int j=0; j<=(len/2-1); j++)
        {
            nums[flag_index+1+j] = nums[flag_index+1+j]^nums[numsSize-1-j];
            nums[numsSize-1-j] = nums[flag_index+1+j]^nums[numsSize-1-j];
            nums[flag_index+1+j] = nums[flag_index+1+j]^nums[numsSize-1-j];
        }
        
    }
    else
    {
        //全部倒序
        for(int i=0; i<=(numsSize/2-1); i++)
        {
            nums[i] = nums[i]^nums[numsSize-1-i];
            nums[numsSize-1-i] = nums[i]^nums[numsSize-1-i];
            nums[i] = nums[i]^nums[numsSize-1-i];
        }

        
    }
for(int k=0; k<numsSize; k++)
   printf("%d  ",nums[k]);
printf("\n");
    
}




int main()
{ 
    int numsSize;
    while(scanf("%d",&numsSize))
    {
       int nums[numsSize+5];
       for(int i=0; i<numsSize; i++)
            scanf("%d",&nums[i]);
       nextPermutation(nums,numsSize);


    }


return 0;
}
