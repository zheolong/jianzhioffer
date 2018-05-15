#include <stdio.h>
#include <stdlib.h>
#include "base/single_linked_list.h"

using namespace base;
node *merge_sorted_list(node *phead1, node *phead2);
int main(void)
{
    node head = {0, NULL};
    insert(&head, 2);
    insert(&head, 4);
    insert(&head, 6);

    node head1 = {1, NULL};
    insert(&head1, 3);
    insert(&head1, 5);
    insert(&head1, 7);
    
    print(merge_sorted_list(&head, &head1)); 
    printf("\n");
}

node *merge_sorted_list(node *phead1, node *phead2)
{
    if (NULL == phead1) return phead2;
    if (NULL == phead2) return phead1;

    node *phead_new = phead1;
    node *pfirst = phead1;
    node *psecond = phead2;
    if (phead1->data > phead2->data) {
        pfirst = phead2;
        psecond = phead1;
        phead_new = phead2;
    }

    while ((NULL != pfirst->next) && (pfirst->next->data <= psecond->data)) {
        pfirst = pfirst->next;
    }
    
    pfirst->next = merge_sorted_list(pfirst->next, psecond);

    return phead_new;
}
