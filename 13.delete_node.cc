#include <stdio.h>
#include <stdlib.h>
#include "base/single_linked_list.h"

using namespace base;
bool delete_node(node **phead, node *to_delete);
int main(void)
{
    node head = {0, NULL};
    insert(&head, 1);
    insert(&head, 2);
    insert(&head, 3);
    
    node *h = &head;
    delete_node(&h, h); 
    print(h);
    printf("\n");

    delete_node(&h, h->next); 
    print(h);
    printf("\n");
}

bool delete_node(node **phead, node *to_delete)
{
    if (NULL == phead || NULL == *phead || NULL == to_delete) {
        printf("invalid\n");
        return false;
    }

    if (NULL != to_delete->next) {
        node *tmp = to_delete->next;
        to_delete->data = tmp->data;
        to_delete->next = tmp->next;

        delete(tmp);
        tmp->next = NULL;
    } else if (*phead == to_delete) {
        node *tmp = *phead;
        *phead = tmp->next;

        delete(tmp);
        tmp->next = NULL;
    } else {
        node *tmp = *phead;
        while ((NULL != tmp) && (tmp->next != to_delete)) {
            tmp = tmp->next;
        }

        if (NULL != tmp) {
            tmp->next = to_delete->next;
            delete(to_delete);
            to_delete->next = NULL;
        } else {
            return false;
        }
    }

    return true;
}
