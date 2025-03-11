#include<stdlib.h>
#include<stdio.h>
#include<stdbool.h>
#include"uthash.h"  
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
typedef struct hashtable
{
   int key; //哈希表的下标,传入目标数组的值
   int val; //哈希表的值,传入目标数组的下标
   UT_hash_handle hh;
}hashtable_s;

hashtable_s *hashtable;

hashtable_s *__hash_find(int ikey)
{
  hashtable_s *tmp_hashtable;
  HASH_FIND_INT(hashtable,&ikey,tmp_hashtable);
  return tmp_hashtable;
}

bool __hash_insert(int ikey, int ival)
{
   hashtable_s *it;
   it= __hash_find(ikey);
   if(it==NULL)
   {
      hashtable_s * tmp_hashtable =(hashtable_s*)calloc(1,sizeof(hashtable_s));
      tmp_hashtable->key=ikey;
      tmp_hashtable->val=ival;
      HASH_ADD_INT(hashtable,key,tmp_hashtable);
      return 1;
   }
   else
   {
      return 0;
   }
}

void __hash_free()
{
   hashtable_s *current,*next;
   HASH_ITER(hh,hashtable,current,next)
   {
      HASH_DEL(hashtable,current);
      free(current);
   }
}



int* twoSum(int* nums, int numsSize, int target, int* returnSize) 
{
   hashtable = NULL ;
   for(int i=0; i<numsSize; i++)
   {
      hashtable_s*tmp;
      tmp = __hash_find(target-nums[i]);
      if (tmp != NULL)
      {
         *returnSize=2;
         int *ret = (int*)calloc(2,sizeof(int));
         *ret = i;
         *(ret+1)= tmp->val;
         return ret;
      }
      else
      __hash_insert(nums[i],i);
   }  
   __hash_free();
   return 0;
}

int main(void) {
   int nums[] = {2, 7, 11, 15};
   int numsSize = sizeof(nums) / sizeof(nums[0]);
   int target = 9;
   int returnSize;
   int *result = twoSum(nums, numsSize, target, &returnSize);

   if (result != NULL) {
       printf("Indices: %d, %d\n", result[0], result[1]);
       free(result);
   } else {
       printf("No solution found.\n");
   }

   return 0;
}