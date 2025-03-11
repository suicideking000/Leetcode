#include<stdlib.h>
#include"uthash.h"  
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

 typedef struct hash
 {
    int key;//下标 哈希表的下标,即传入数组的值
    int value;//值 传入数组的下标
    UT_hash_handle hh;
 }hash;

 hash * hashtable;

 hash* hash_find(int ikey)
 {
    hash *s;
    HASH_FIND_INT(hashtable,&ikey,s); //HASH_FIND_INT是一个宏，用于处理整数类型的键。
                                     //这里，users是指向哈希表头部的指针，&user_id是指向要查找的键的指针，而s是一个指向uthash结构体（或任何包含UT_hash_handle hh;成员的结构体）的指针，用于存储找到的条目（如果找到的话）。
    return s;
 }

 void hash_insert(int ikey,int ivalue)
 {
    hash *s;
    s= hash_find(ikey);                
    if(s==NULL)
    {
        hash *tmp=(hash*)malloc(sizeof(hash));
        tmp->key=ikey;
        tmp->value=ivalue;
        HASH_ADD_INT(hashtable,key,tmp);
    }
    else
    {
        s->value=ivalue;
    }
 }

 int* twoSum(int* nums, int numsSize, int target, int* returnSize) 
 {
   hashtable=NULL;
   for(int i=0;i<numsSize;i++)
   {
     struct hash *s=hash_find(target-nums[i]);
      if(s!=NULL)
      {
         int *ret=(int*)malloc(sizeof(int)*2);
         ret[0]=s->value;
         ret[1]=i;
         *returnSize=2;
         return ret;
      }
      hash_insert(nums[i],i);
   }
   *returnSize=0;
   return NULL;

    
 }

 int main(void)
 {
   return 0;
 }