int searchInsert(int* nums, int numsSize, int target) 
{
    int ans = -1;
    for(int i=0; i<numsSize; i++)
    {
       if(nums[i]>=target) return i;
       //if(nums[i]>target) return i;
    }
    return numsSize;
    
}
