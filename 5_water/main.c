#include<stdlib.h>
#include<stdio.h>

int maxArea(int* height, int heightSize) {
int *left=height;
int *right=height+heightSize-1;
int max=0;
//双指针向中间收缩,哪边长往哪边缩
while(left!=right)
{
    int area=(*left>*right?*right:*left)*(right-left);
    max=area>max?area:max;
    if(*left>*right)
    {
        right--;
    }
    else
    {
        left++;
    }
}    
return max;
}