#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void moveZeroes(int* nums, int numsSize) {
int *fast;
int *slow;
fast=slow=nums;
while(fast-nums<numsSize)
{
    if(*fast!=0)
    {
        *slow=*fast;
        slow++;
    }
    fast++;
}

while(slow-nums<numsSize)
{
    *slow=0;
    slow++;
}

void printArray(int* nums, int numsSize) {
    for (int i = 0; i < numsSize; i++) {
        printf("%d ", nums[i]);
    }
    printf("\n");
}

int main(void) {
    int nums[] = {0, 1, 0, 3, 12,0,1};
    int numsSize = sizeof(nums) / sizeof(nums[0]);

    printf("Original array: ");
    printArray(nums, numsSize);

    moveZeroes(nums, numsSize);

    printf("Array after moving zeroes: ");
    printArray(nums, numsSize);

    return 0;
}