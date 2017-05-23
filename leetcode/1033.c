int search(int* nums, int numsSize, int target)
{
    for(int i=0; i<numsSize; i++)
    {
        if(nums[i]==target) return i;
    }

return -1;

    
}


/*更好的方法
//先用二分法找到最大元素，将数组切分成两个有序数组，再进行二分查找
class Solution {
public:
    int search(int A[], int n, int target) {
        if(n==1)
            return (target==A[0])?0:-1;
            
        //find the maximum first
        int low = 0;
        int high = n-1;
        while(low < high)
        {
            int mid = (low+high)/2;
            if(A[mid] < A[low])
                high = mid-1;
            else if(A[mid] > A[low])
                low = mid;
            else
            {//low+1==high
                if(A[high]>A[low])
                    low = high;
                break;
            }
        }
        int ind = low;
        //to here, low is the index of maximum
        //0~ind, ind+1~n-1 are two sorted arrays
        if(target >= A[0])
        {//first array: 0~ind
            low = 0;
            high = ind;
            while(low <= high)
            {
                int mid = (low+high)/2;
                if(target == A[mid])
                    return mid;
                else if(target > A[mid])
                    low = mid+1;
                else
                    high = mid-1;
            }
            return -1;
        }
        else
        {//second array: ind+1, n-1
            low = ind+1;
            high = n-1;
            while(low <= high)
            {
                int mid = (low+high)/2;
                if(target == A[mid])
                    return mid;
                else if(target > A[mid])
                    low = mid+1;
                else
                    high = mid-1;
            }
            return -1;
        }
    }
};


*/
