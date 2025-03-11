/* 0 1 2 3 4 5 6 7 9 8*/
/* ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ */
/* 0 1 1 2 2 2 2 3 3 3*/
/*完全二叉树的数组存储方式*/
/* 特性：
   - 完全二叉树的节点可以使用数组来表示，不需要使用指针或者链表结构，这是因为节点的位置与数组索引之间存在一种对应关系。
   - 根据这种对应关系，如果一个节点的索引是i，那么它的左子节点的索引是2*i + 1，右子节点的索引是2*i + 2。
   - 因为完全二叉树的特殊结构，使用数组存储可以更加节省内存空间，也更容易实现。
*/
#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}
void AdjustDown(int *a,int n,int parent)
{
    int child=2*parent+1;
    while(child<n)
    {
        //如果右孩子存在,比较左右孩子大小
        if(child+1<n&&a[child]<a[child+1])
        {
            child++;
        }
        //比较孩子和父节点大小
        if(a[child]>a[parent])
        {
            swap(&a[child],&a[parent]);
            //向子节点下沉
            parent=child;
            child=2*parent+1;
        }
        else
        {
            break;
        }
    }
}

void HeapSort(int *a,int n)
{
    //建堆
    for(int i=(n-1-1)/2;i>=0;i--)//最后一个非叶子节点
    {
        AdjustDown(a,n,i);
    }
    //排序
    for(int i=0;i<n;i++)
    {
        swap(&a[0],&a[n-1-i]);
        AdjustDown(a,n-1-i,0);
    }
}

int main()
{
    int a[]={3,1,2,5,4,6,7,9,8,0};
    int n=sizeof(a)/sizeof(a[0]);
    HeapSort(a,n);
    for(int i=0;i<n;i++)
    {
        printf("%d ",a[i]);
    }
    printf("\n");
    return 0;
}