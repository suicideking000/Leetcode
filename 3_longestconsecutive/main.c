#include<stdlib.h>
#include<stdio.h>
#include"uthash.h"  


typedef struct hash
 {
    int key;//存储数组的值作为键
    int value; //存储数组的下标作为值
    int num;//数组中当前数作为序列的位置 比如[1,0,5,8],其中0的num为1,1的num为2,5的num为1,8的num为1
    UT_hash_handle hh;
 }hash;

 hash * hashtable;
 int max=0;

 hash* hash_find(int ikey)
 {
    hash *s;
    HASH_FIND_INT(hashtable,&ikey,s); //HASH_FIND_INT是一个宏，用于处理整数类型的键。
                                     //这里，users是指向哈希表头部的指针，&user_id是指向要查找的键的指针，而s是一个指向uthash结构体（或任何包含UT_hash_handle hh;成员的结构体）的指针，用于存储找到的条目（如果找到的话）。
    return s;
 }

 void hash_insert(int ikey, int ivalue)
 {

    hash *it;
    it = hash_find(ikey);
    if(it == NULL)//有新的数字
    {
        it = (hash*)malloc(sizeof(hash));
        it->key = ikey;
        it->value = ivalue;
        it->num = 1;
        HASH_ADD_INT(hashtable,key,it);

    //查找上下有没有连着的数字
    hash *up, *down;
    up = hash_find(ikey+1);
    down = hash_find(ikey-1);
    if(up != NULL)
    {
        if(down != NULL)
        {
            //如果上下都有连着的数字
            it->num = up->num + down->num + 1;
            up=hash_find(ikey+up->num);
            down=hash_find(ikey-down->num);
            up->num = it->num;
            down->num = it->num;
            if(it->num > max)
            {
                max = it->num;
            }
        }
        else
        {
            //如果只有上面有连着的数字
            it->num = up->num + 1;
            up=hash_find(ikey+up->num);
            up->num = it->num;
            if(it->num > max)
            {
                max = it->num;
            }
        }
    }
    else if(down !=NULL)
    {
        //如果只有下面有连着的数字
        it->num = down->num + 1;
        down=hash_find(ikey-down->num);
        down->num = it->num;
        if(it->num > max)
        {
            max = it->num;
        }
    }
    else
    {
        //如果上下都没有连着的数字
        if(it->num > max)
        {
            max = it->num;
        }
    }
    }
    else
    {
        it->value = ivalue;
    }

 }


void freehash(){
    hash *current_user, *tmp;
    HASH_ITER(hh, hashtable, current_user, tmp) {
        HASH_DEL(hashtable,current_user);
    }
}
int longestConsecutive(int* nums, int numsSize) {
    for (int i = 0; i < numsSize; i++)
    {
        hash_insert(nums[i], i);
    }
    return max;
}
int main(void) {
    int nums[] = {1,2,4,5,3};
    int numsSize = sizeof(nums) / sizeof(nums[0]);
    int result = longestConsecutive(nums, numsSize);
    printf("The longest consecutive sequence length is: %d\n", result);
    return 0;
}