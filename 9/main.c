#include<stdlib.h>
#include<stdio.h>
#include<stdbool.h>

#define HASH_TAIL  'z'-'a'+2

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

 //如果使用哈希表,则需要将字符串p中的字符存入哈希表,然后遍历字符串s,每次遍历时,将字符串s中的字符存入哈希表,并且比较两个哈希表是否相等,如果相等,则将当前位置存入结果数组


bool hash_compare(int*hash1 ,int*hash2)
{
    for(int i=0;i<HASH_TAIL;i++)
    {
        if(hash1[i]!=hash2[i])
        {
            return false;
        }
    }
    return true;

}

int*hash1_save(char*s)
{
    int size=0;
    int*hash1=(int*)malloc(sizeof(int)*HASH_TAIL);
    memset(hash1,0,sizeof(int)*HASH_TAIL);
    while(s!='\0')
    {
        hash1[*s-'a']++;
        size++;
        s++;
    }
    hash1[HASH_TAIL]=size;
}


int* findAnagrams(char* s, char* p, int* returnSize) {
    *returnSize=0;
    int len=strlen(p);
    int orilen=strlen(s);
    if(len>orilen)
    {
        return NULL;
    }
    int *hash1=hash1_save(p);
    int *hash2=(int*)malloc(sizeof(int)*HASH_TAIL);
    while(s!='\0')
    {
        hash2[*s-'a']++;
        if(strlen(s)<orilen-len)
        {
            hash2[*(s-1)-'a']--;
        }
        if(hash_compare(hash1,hash2))
        {
            *returnSize++;

        }
        s++;
    }

    
}