#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "hash.h"

int main(int argc, char *argv[])
{
    Hash_link HASH = Hash_create();
    if(HASH == NULL)
    {
        printf("the memory assigning for hash list-HASH failed!\n");
        return -1;
    }
    printf("please enter number into the esstablished HASH list:\n");
    int j, k;
    data_t insert[12];
    for(j = 0; j < 12; j++)
    {
        scanf("%d", &insert[j]);
    }

    for(j = 0; j < 12; j++)
    {
        printf("%d ", insert[j]);
    }
    
    for(k = 0; k < 12; k++)
    {
        Hash_insert(HASH, insert[k]);
    }
    printf("%d\n", Hash_search(HASH, 67));
    Hash_delete(HASH);
    return 0;
}
