#include <stdio.h>
#include <stdlib.h>

struct ComplexListNode
{
    int data;
    ComplexListNode *next;
    ComplexListNode *sibling;
};

void clone_node(ComplexListNode *head);
void connect_sibling(ComplexListNode *head);
ComplexListNode *split_nodes(ComplexListNode *head);

int main(void)
{
    ComplexListNode nodes[5];
    for (int i = 0; i < 5; i++) {
        nodes[i].data = i;
        if (i < 4)
            nodes[i].next = &nodes[i+1];
        nodes[i].sibling = NULL;
    }
    nodes[4].next = NULL;

    nodes[0].sibling = &nodes[2];
    nodes[1].sibling = &nodes[4];
    nodes[3].sibling = &nodes[1];

    clone_node(&nodes[0]);
    connect_sibling(&nodes[0]);
    ComplexListNode *new_head = split_nodes(&nodes[0]);
    ComplexListNode *p = new_head;
    while (NULL != p) {
        printf("%d ", p->data);
        p = p->next;
    }

    printf("\n");
    int index[] = {0,1,3};
    for (int i = 0; i < 3; i++)
        printf("sibling of nodes[%d]: %d\n", index[i], nodes[index[i]].sibling->data);
}

void clone_node(ComplexListNode *head)
{
    if (NULL == head)
        return;

    ComplexListNode *p = head;
    ComplexListNode *q = p->next;
    while (NULL != p) {
        ComplexListNode *new_node = (ComplexListNode *)malloc(sizeof(ComplexListNode));
        new_node->data= p->data;
        new_node->next = q;
        new_node->sibling = NULL;

        p->next = new_node;
        p = q;
        if (NULL != q)
            q = q->next;
    }
}

void connect_sibling(ComplexListNode *head)
{
    if (NULL == head)
        return;

    int n = 1;
    ComplexListNode *p = head;
    while (NULL != p) {
        if (n % 2 == 0) {
            if (NULL != p->sibling)
                p -> sibling = p->sibling->next;
        }
        p = p->next;
        n++;
    }
}

ComplexListNode *split_nodes(ComplexListNode *head)
{
    if (NULL == head)
        return NULL;

    ComplexListNode *p = head;
    ComplexListNode *q = head->next;
    ComplexListNode *new_head  = q;

    while (NULL != q) {
        p->next = q->next;

        if (q->next != NULL)
            q->next = q->next->next;

        p = p->next;
        q = q->next;
    }

    return new_head;
}
