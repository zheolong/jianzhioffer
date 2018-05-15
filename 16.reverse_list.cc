#include <stdio.h>
#include <stdlib.h>
#include "base/single_linked_list.h"

using namespace base;
node *reverse(node *phead);
int main(void)
{
    node head = {0, NULL};
    insert(&head, 1);
    insert(&head, 2);
    insert(&head, 3);
    
    node *h = &head;
    node *new_head = reverse(h);
    print(new_head);
    printf("\n");
}

node *reverse(node *phead)
{
    if (NULL == phead || NULL == phead->next )
        return phead;

    node *p = phead;
    node *q = p->next;
    node *r = q->next;

    do {
        q->next = p;
        p = q;
        q = r;
        if (NULL != r)
            r = r->next;
        else
            break;
    } while (1);

    phead->next = NULL;

    return p;
}
