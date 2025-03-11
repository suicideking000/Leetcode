#include <stdio.h>
#include<stdlib.h>
#include<string.h>
//递归实现
void _MergeSort(int *a,int*tmp,int begin,int end)
{
    if(begin==end)//当分成只有一个元素时直接返回
    return;

    int mid=(begin+end)/2;
    _MergeSort(a,tmp,begin,mid);
    _MergeSort(a,tmp,mid+1,end);

    //归并
    int begin1=begin, end1=mid;
    int begin2=mid+1, end2=end;
    int i=begin;
    while(begin1<=end1&&begin2<=end2)
    {
        if(a[begin1]<a[begin2])
        {
            tmp[i++]=a[begin1++];
        }
        else
        {
            tmp[i++]=a[begin2++];
        }
    }
    while(begin1<=end1)
    {
        tmp[i++]=a[begin1++];
    }
    while(begin2<=end2)
    {
        tmp[i++]=a[begin2++];
    }
    memcpy(a+begin,tmp+begin,sizeof(int)*(end-begin+1));
}
//非递归实现
void _MergeSortNonR(int*a ,int n)
{
    int *tmp=(int*)malloc(sizeof(int)*n);
    if (tmp==NULL)
    {
        return;
    }
    int gap =1;
    while (gap<n)
    {
        for(int i=0; i<n;i+=2*gap)
        {
            int begin1=i;
            int end1=begin1+gap-1;
            int begin2=end1+1;
            int end2=begin2+gap-1;
            //printf("[%d, %d],[%d, %d];", begin1, end1, begin2, end2);
			//存在的越界情况,以10个数据为例
			//打印结果:
			//gap = 1->:[0, 0],[1, 1];[2, 2],[3, 3];[4, 4],[5, 5];[6, 6],[7, 7];[8, 8],[9, 
            //9];
			//gap = 2->: [0, 1] , [2, 3];[4, 5], [6, 7];[8, 9], [10, 11];
			//gap = 4-> : [0, 3] , [4, 7];[8, 11], [12, 15];
			//gap = 8-> : [0, 7] , [8, 15];
			//情况1:gap == 8的区间[8, 15],只有end2越界
			//情况2:gap == 2的区间[10, 11]，begin2和end2越界
			//情况3:gap == 4的区间[8, 11],[12, 15] end1,begin2和end2越界
			//上述的情况2和情况3可以合为1种情况(则[begin2，end2]区间不存在),该情况下不需要归并
			//这个判断语句处理的是情况2和情况3，当begin2越界的时候，不用处理，当end1越界的时    
            //候，begin2也越界了，也不用处理
            if(begin2>=n)
            {
                continue;
            }
            if(end2>=n)
            {
                end2=n-1;
            }
            int j=begin1;
            while(begin1<=end1&&begin2<=end2)
            {
                if(a[begin1]<a[begin2])
                {
                    tmp[j++]=a[begin1++];
                }
                else
                {
                    tmp[j++]=a[begin2++];
                }
            }
            while(begin1<=end1)
            {
                tmp[j++]=a[begin1++];
            }
            while(begin2<=end2)
            {
                tmp[j++]=a[begin2++];
            }
            memcpy(a+begin1,tmp+begin1,sizeof(int)*(end2-begin1+1));
        }
        gap*=2;
    }
    free(tmp);
    tmp=NULL;
}
void main()
{
    int a[]={3,2,1,4,5,6,7,8,9,10};
    int tmp[10];
    _MergeSort(a,tmp,0,9);
    for(int i=0;i<10;i++)
    {
        printf("%d ",a[i]);
    }
    printf("\n");
}