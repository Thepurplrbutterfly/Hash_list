#ifndef _HASH_
typedef int data_t;
#define N 13
typedef  struct node{
    data_t key;
    data_t value;
    struct node * next;
} node_struct, * node_link;

typedef struct {
    node_struct hash_A[N];
} Hash_Array, * Hash_link;

Hash_link Hash_create();
data_t Hash_insert(Hash_link, data_t);
int Hash_search(Hash_link, data_t);
int Hash_delete(Hash_link);
void Hash_freem(Hash_link);
#endif
