#include "base/binary_tree.h"
#include <stdio.h>
#include <stdlib.h>
#include <queue>
using namespace base;

bool verify_sequence_of_bst(int arr[], int start, int end);
int main(void)
{
    int data[] = {5, 7, 6, 9, 11, 10, 8};
    printf("%d\n", verify_sequence_of_bst(data, 0, 6));

    int data1[] = {7, 4, 6, 5};
    printf("%d\n", verify_sequence_of_bst(data1, 0, 3));
}

bool verify_sequence_of_bst(int arr[], int start, int end)
{
    if (start >= end)
        return true;
    
    int root = arr[end];
    int i = start;
    for (; i <= end - 1; ++i) {
        if (arr[i] >= root) {
            break;
        }
    }

    int mark = i;
    for (; i < end - 1; ++i) {
        if (arr[i] < root)
            return false;
    }

    return verify_sequence_of_bst(arr, start, mark - 1)
     && verify_sequence_of_bst(arr, mark, end - 1);
}
