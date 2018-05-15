#include <stdio.h>
#include <stdlib.h>
#include "base/single_linked_list.h"

using namespace base;
node *kth_to_tail(node *phead, int k);
int main(int argc, char *argv[]) 
{
    node head = {0, NULL};
    insert(&head, 1);
    insert(&head, 2);
    insert(&head, 3);
    
    node *h = &head;
    node *kth = kth_to_tail(h, atoi(argv[1])); 
    if (NULL != kth) {
        printf("%d", kth->data);
        printf("\n");
    }
}

node *kth_to_tail(node *phead, int k)
{
    if (NULL == phead || k < 0) {
        return NULL;
    }

    node *p = phead;
    int i = 1;
    for (; i < k; ++i) {
        if (NULL != p->next) 
            p = p->next;
        else 
            break;
    }

    if (i!=k) {
        return NULL;
    }

    while (NULL != p->next) {
        p = p->next;
        phead = phead->next;
    }

    return phead;
}

