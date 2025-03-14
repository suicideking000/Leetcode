#include<string.h>
#include<stdlib.h>
#include<stdio.h>

//输入描述:输入包括两个正整数a,b(1 <= a, b <= 1000),输入数据包括多组。
//输出描述:输出a+b的结果
/*
输入例子：
1 5
10 20
输出例子：
6
30
*/

void func1()
{
    int a,b;
    while(scanf("%d %d",&a,&b)!=EOF)
    {
        printf("%d\n",a+b);
    }
}

//输入描述:输入第一行包括一个数据组数t(1 <= t <= 100)
//        接下来每行包括两个正整数a,b(1 <= a, b <= 1000)
//输出描述:输出a+b的结果
/*
输入例子：
2
1 5
10 20
输出例子：
6
30
*/

void func2()
{
    int n;
    int a,b;
    scanf("%d",&n);
    while(n-- >0)
    {
        scanf("%d %d",&a,&b);
        printf("%d\n",a+b);
    }
}

//输入包括两个正整数a,b(1 <= a, b <= 10^9),输入数据有多组, 如果输入为0 0则结束输入
//输出a+b的结果
/*
输入例子：
1 5
10 20
0 0
输出例子：
6
30
*/

void func3()
{
    int a,b;
    while(scanf("%d %d",&a,&b),a!=0||b!=0)
    {
        printf("%d\n",a+b);
    }
}

//输入数据包括多组。
//每组数据一行,每行的第一个整数为整数的个数 n (1 < n < 1000), n 为 0 的时候结束输入。
//接下来 n 个正整数,即需要求和的每个正整数。
//输出描述:每组数据输出求和的结果
/*
输入例子：
4 1 2 3 4
5 1 2 3 4 5
0
输出例子：
10
15
*/

void func4()
{
    int sum=0;
    int a;
    while(scanf("%d",&a),a!=0)
    {
        while(a-- >0)
        {
            int b;
            scanf("%d",&b);
            sum+=b;
        }
        printf("%d\n",sum);
        sum=0;
    }
}




int main(void)
{
    func4();
    return 0;
}