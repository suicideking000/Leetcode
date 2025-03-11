#include<stdlib.h>
#include<stdio.h>

//创建两个指针,同时从最左侧触发,右指针先行,将遇到过的字母次数存入表中,类似哈希,同时记录长度,遇到次数大于2的字母时,左指针滑动至重复字母的下一个位置,同时更新长度,直至右指针到达字符串末尾

int lengthOfLongestSubstring(char*s)
{
    int map[128]={0};
    int left=0;
    int right=0;
    int length=0;
    while(s[right]!='\0')
    {
        map[s[right]]++;
        while(map[s[right]]>1)
        {
            map[s[left]]--;
            left++;
        }
        if(right-left+1>length)
        {
            length=right-left+1;
        }

    }

    return length;
}

