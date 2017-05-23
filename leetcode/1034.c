/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* searchRange(int* nums, int numsSize, int target, int* returnSize)
{
     int* ans = (int*)malloc(sizeof(int)*2);
     int bg = -1;
     int ed = -1;
     for(int i=0; i<numsSize; i++)
     {
         if(i==0&&nums[i]==target) {bg = 0; ed = 0; continue;}
         
         if(nums[i-1]<target&&nums[i]==target) bg = i;
         if(nums[i-1]==target&&nums[i]>target) ed = i-1;
         
         if(i==numsSize-1)
         {
            if(nums[i-1]<target&&nums[i]==target) bg = i;    
            
            if(nums[i]==target)ed = i;
         }
         
     }
     ans[0] = bg;
     ans[1] = ed;
     *returnSize = 2;  //注意这个东西也要赋值
    return ans;
}



/*
//更好的还是二分法
int* searchRange(int* nums, int numsSize, int target, int* returnSize) {  
    int* res=(int*)malloc(sizeof(int)*2);  
    int l=0,r=numsSize-1,mid;  
    while(l<=r){  
        mid=(l+r)>>1;  
        if(nums[mid]==target)break;  
        else if(nums[mid]>target)r=mid-1;  
        else l=mid+1;  
    }  
    if(l<=r){  
        l=mid-1;  
        while(l>=0 && nums[l]==nums[mid])l--;  
        r=mid+1;  
        while(r<numsSize && nums[r]==nums[mid])r++;  
        res[0]=l+1;res[1]=r-1;  
        *returnSize=2;  
        return res;  
    }else{  
        res[0]=-1;res[1]=-1;  
        *returnSize=2;  
        return res;  
    }  
}


*/
