/*从左向右遍历,先找到一个最高的,指针1指向它,然后分左右,先向左,找到第二高的,指针2指向它,求出第1第2高的中间的水,指针1指向第二高的,指针2继续向左找第三高的...*/
#include<stdlib.h>
#include<stdio.h>
#include<limits.h>


int findmax(int *height,int heightSize)
{
    int max=0;
    int maxindex=0;
    for(int i=0;i<heightSize;i++)
    {
        if(height[i]>max)
        {
            max=height[i];
            maxindex=i;
        }
    }
    return maxindex;
}


int trap(int* height, int heightSize) {
    int maxindex=findmax(height,heightSize);
    int sum=0;
    //先向左找
    int left =maxindex;
    int right=maxindex;
    while(left>0)
    {
        left=findmax(height,right);
        for(int i=left+1;i<right;i++)
        {
            sum+=height[left]-height[i];
        }
        right=left;
    }
    //向右找
    left=maxindex;
    right=maxindex;
    while(right<heightSize-1)
    {
        right=findmax(height+left+1,heightSize-left-1)+left+1;
        if (right == 0) break; // 如果找不到更高的柱子，退出循环
        for(int i=left+1;i<right;i++)
        {
            sum+=height[right]-height[i];
        }
        left=right;
    }
    return sum;
}

void printArray(int* nums, int numsSize) {
    for (int i = 0; i < numsSize; i++) {
        printf("%d ", nums[i]);
    }
    printf("\n");
}

int main(void) {
    int height[] = {2,1,2,1};
    int heightSize = sizeof(height) / sizeof(height[0]);

    printf("Height array: ");
    printArray(height, heightSize);

    int result = trap(height, heightSize);

    printf("Total water trapped: %d\n", result);

    return 0;
}