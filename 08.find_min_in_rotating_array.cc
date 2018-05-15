#include <stdio.h>

int find_min_in_rotating_array(int arr[], int arr_size);
int main(void)
{
    int arr[] = {1,1,1,0,1};
    int pos = find_min_in_rotating_array(arr,5);
    printf("%d\n", pos);

    int arr1[] = {1,2,3,0,1};
    pos = find_min_in_rotating_array(arr1,5);
    printf("%d\n", pos);

    int arr2[] = {1,2,3,-1,2};
    pos = find_min_in_rotating_array(arr2,5);
    printf("%d\n", pos);

    int arr3[] = {1,2,3,-1,0,-1}; // can not recognize this situation
    pos = find_min_in_rotating_array(arr3,6);
    printf("%d\n", pos);
}

int find_min_in_rotating_array(int arr[], int arr_size)
{
    if (arr_size <= 0) {
        printf("invalid array size\n");
        return -1;
    }

    int start = 0;
    int end = arr_size - 1;
    int target = start;

    if (arr[end] > arr[start]) {
        printf("invalid array\n");
        return -1;
    }

    while (arr[end] <= arr[start])
    {
        if (end - start == 1) { 
            target = end;
            break;
        }

        target = (start + end) >> 1;
        if ((arr[target] == arr[start]) && (arr[target] == arr[end])) {
            int min = 0;
            for(int i = 0; i < arr_size - 1; ++i) {
                if (arr[i] > arr[i+1]) {
                    min = i+1;
                    break;
                }
            }
            return min;
        }

        if (arr[target] >= arr[start]) {
            start = target;
        }

        if (arr[target] <= arr[start]) {
            end = target;
        }
    }

    return target;
}
