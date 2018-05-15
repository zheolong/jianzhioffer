#include "base/single_linked_list.h"
#include <stdio.h>
#include <stack>

using namespace base;

void reverse_print(node *phead);
void reverse_print_recursively(node *phead);
int main(void)
{
    node head = {0, NULL};
    insert(&head, 1);
    insert(&head, 2);
    insert(&head, 3);
    reverse_print(&head);
    printf("\n");
    reverse_print_recursively(&head);
}

void reverse_print(node *phead)
{
    if (NULL == phead) {
        printf("phead is null");
        return;
    }

    std::stack<node *> ns;
    node *p = phead;

    while (NULL != p) {
        ns.push(p);
        p = p->next;
    }

    while (!ns.empty()) {
        p = ns.top();
        printf("%d ", p->data);
        ns.pop();
    }
}

void reverse_print_recursively(node *phead)
{
    if (NULL == phead)
        return;

    reverse_print_recursively(phead->next);
    printf("%d ", phead->data);
}
