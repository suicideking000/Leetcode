#include<stdlib.h>
#include<stdio.h>
#include"uthash.h"  

//将字符串数组中的每个字符串按照字母从小到大顺序重新排列后,将排列后的字符串作为哈希表的键存入,同时将原数组存入哈希表中,将具有相同字符串顺序的字符串存入同一个数组中,作为哈希表的值
#define MAX_NUM 10000
#define MAX_LEN 100

//字符串再排序

int cmp(const void *a,const void *b)
{
    return *(char*)a-*(char*)b;
}

void reshuffle (char *str)
{
    int len = strlen(str);
    qsort(str, len, sizeof(char), cmp);
}

typedef struct hash
 {
    char *key;
    char ori_array[MAX_NUM][MAX_LEN];
    int num;//存入的字符串数量
    UT_hash_handle hh;
 }hash;

 hash * hashtable;
 int g_size=0;

 hash* hash_find(char *ikey)
 {
    hash *s;
    HASH_FIND_STR(hashtable,ikey,s); //HASH_FIND_INT是一个宏，用于处理整数类型的键。
                                     //这里，users是指向哈希表头部的指针，&user_id是指向要查找的键的指针，而s是一个指向uthash结构体（或任何包含UT_hash_handle hh;成员的结构体）的指针，用于存储找到的条目（如果找到的话）。
    return s;
 }

 void hash_insert(char* ikey,char* iarray)
 {
    hash *it;
    it = hash_find(ikey);
    if(it == NULL)//有新的同分异构字符串
    {
        hash *tmp = (hash*)malloc(sizeof(hash));
        tmp->key = (char*)malloc(sizeof(char)*MAX_LEN);
        strcpy(tmp->key,ikey);
        strcpy(tmp->ori_array[0],iarray);
        tmp->num = 1;
        HASH_ADD_STR(hashtable,key,tmp);
        g_size++;
    }
    else
    {
        strcpy(it->ori_array[it->num],iarray);
        it->num++;
    }
 }

void freehash(){
    hash *current_user, *tmp;
    HASH_ITER(hh, hashtable, current_user, tmp) {
        free(current_user->key);
        HASH_DEL(hashtable,current_user);
    }
}

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
char*** groupAnagrams(char** strs, int strsSize, int* returnSize, int** returnColumnSizes) {
    if(strsSize==0)
    {
        *returnSize = 0;
        return NULL;
    }

    hashtable = NULL;
    for(int i=0;i<strsSize;i++)
    {
        char *tmp = (char*)malloc(sizeof(char)*MAX_LEN);
        strcpy(tmp,strs[i]);
        reshuffle(tmp);
        hash_insert(tmp,strs[i]);
    }//将每个成员数组再排序,将原数组和排序后数组存入哈希表
    *returnSize = g_size;
    *returnColumnSizes = (int*)malloc(sizeof(int)*g_size);
    char ***ret = (char***)malloc(sizeof(char**)*g_size);

    hash *current_user, *tmp;
    int index =0;
    HASH_ITER(hh, hashtable, current_user, tmp) 
    {
        int num = current_user->num;
        (*returnColumnSizes)[index] = num;
        ret[index] = (char**)malloc(sizeof(char*)*num);
        for(int i=0;i<num;i++)
        {
            ret[index][i] = (char*)malloc(sizeof(char) * (strlen(current_user->key)+1));
            strcpy(ret[index][i],current_user->ori_array[i]);
        }
        index++;
    }
    freehash();
    hashtable=NULL;
    
    return ret;



}

