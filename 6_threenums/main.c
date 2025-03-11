#include<stdlib.h>
#include<stdio.h>
#include"uthash.h"

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int PartSort(int *arr,int left,int right)
{
    int Key=left;
    while(left<right)
    {
        while(left<right&&arr[right]>=arr[Key])
        {
            right--;
        }
        while(left<right&&arr[left]<=arr[Key])
        {
            left++;
        }
        if(left<right)
        {
            swap(&arr[left],&arr[right]);
        }
    }
    swap(&arr[Key],&arr[left]);
    return left;

}

void QuickSort(int *arr,int left,int right)
{
    if(left>=right)
    {
        return;
    }
    int div=PartSort(arr,left,right);
    QuickSort(arr,left,div-1);
    QuickSort(arr,div+1,right);
}



/*双指针*/

int** threeSum(int* nums, int numsSize, int* returnSize, int** returnColumnSizes)
{
    int **ret=(int**)malloc(sizeof(int*)*10000);
    *returnSize=0;
    //从小到大排序
    QuickSort(nums,0,numsSize-1);

    for(int i=0;i<numsSize-1;i++)
    {
        int left=i+1;
        int right=numsSize-1;
        while(left<right)
        {
            int sum=nums[i]+nums[left]+nums[right];
            if(sum==0)
            {
                ret[*returnSize]=(int*)malloc(sizeof(int)*3);
                ret[*returnSize][0]=nums[i];
                ret[*returnSize][1]=nums[left];
                ret[*returnSize][2]=nums[right];
                (*returnSize)++;
                while(left<right&&nums[left]==nums[left+1])
                {
                    left++;
                }
                while(left<right&&nums[right]==nums[right-1])
                {
                    right--;
                }
                left++;
                right--;
            }
            else if(sum<0)
            {
                left++;
            }
            else
            {
                right--;
            }
        }
    }
    *returnColumnSizes=(int*)malloc(sizeof(int)*(*returnSize));
    for(int i=0;i<*returnSize;i++)
    {
        (*returnColumnSizes)[i]=3;
    }
    return ret;
}
void printResult(int** result, int returnSize, int* returnColumnSizes) {
    for (int i = 0; i < returnSize; i++) {
        printf("[");
        for (int j = 0; j < returnColumnSizes[i]; j++) {
            printf("%d", result[i][j]);
            if (j < returnColumnSizes[i] - 1) {
                printf(", ");
            }
        }
        printf("]\n");
    }
}

int main(void) {
    int nums[] = {-1, 0, 1, 2, -1, -4};
    int numsSize = sizeof(nums) / sizeof(nums[0]);
    int returnSize;
    int* returnColumnSizes;
    int** result = threeSum(nums, numsSize, &returnSize, &returnColumnSizes);

    printf("Triplets that sum to zero:\n");
    printResult(result, returnSize, returnColumnSizes);

    // 释放内存
    for (int i = 0; i < returnSize; i++) {
        free(result[i]);
    }
    free(result);
    free(returnColumnSizes);

    return 0;
}