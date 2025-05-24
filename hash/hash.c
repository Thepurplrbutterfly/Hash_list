#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "hash.h"

/*哈希表Hash创建函数*/
Hash_link Hash_create()
{
    Hash_link HASH = (Hash_link)malloc(sizeof(Hash_Array));
    if(HASH == NULL)
    {
        printf("the memory assigning for hash list-HASH failed!\n");
        return NULL;
    }
    //对哈希表中的头结构体数组进行初始化
    memset(HASH, 0, sizeof(Hash_Array)); //利用memset函数对指针HASH指向的结构体中的所有元素进行填0初始化操作，memset是将目标内存中的每一个字节指向的元素都设置为0
    return HASH;
}

/*Hash表元素插入函数*/
data_t Hash_insert(Hash_link HASH, data_t key)
{
    if(HASH == NULL)
    {
        printf("the memory assigning for hash list-HASH failed!\n");
        return -1;
    }
    node_link p = (node_link)malloc(sizeof(node_struct));
    if(p == NULL)
    {
        printf("the memory assigning for inserted node failed!\n");
        return -1;
    }
    p->key = key;
    p->value = p->key % N;
    p->next = NULL;
    node_link q = &(HASH->hash_A[p->value]); //利用自定义指针寻找目标链的头指针，并实现后续插入操作
    while((q->next) && (q->next->key < p->key))
    {
        q = q->next;
    }
    p->next = q->next;
    q->next = p;
    return 0;
}

/*Hash表中元素查找函数*/
int Hash_search(Hash_link HASH, data_t search_value)
{
    if(HASH == NULL)
    {
        printf("the memory assigning for hash list-HASH failed!\n");
        return -1;
    }
    int i;
    for(i = 0; i < N; i++)
    {
        node_link q = &(HASH->hash_A[i]);
        while(q->next)
        {
            if(q->next->key == search_value)
            {
                printf("the search_value:%d is located in %p\n", search_value, &(HASH->hash_A[i])); 
                return i; 
            }
            q = q->next;
        }
    }
    printf("the search _value is not located in the Hash list!\n");
    return 0;
}

/*Hash表中节点删除函数*/
int Hash_delete(Hash_link HASH)
{
    if(HASH == NULL)
    {
        printf("the memory assigning for hash list-HASH failed!\n");
        return -1;
    }
    int i, RET;
    for(i = 0; i < N; i++)
    {
        node_link p = &(HASH->hash_A[i]);
        while(p->next)
        {
            node_link q = p->next;
            RET = q->key;
            p->next = q->next;
            free(q);
            printf("the value of %d is removed from the HASH list\n", RET);
        }
    }
    printf("i= %d\n", i);
    return 0;
}

/*Hash表内存释放函数*/
void Hash_freem(Hash_link HASH)
{
    if(HASH == NULL)
    {
        printf("the memory assigning for hash list-HASH failed!\n");
        return ;
    } 
    int i;
    for(i = 0; i < N; i++)
    {
        free(&(HASH->hash_A[i]));
    }
    free(HASH);
    return ;
}
