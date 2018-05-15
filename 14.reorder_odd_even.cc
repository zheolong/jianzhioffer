#include <stdio.h>
#include <stdlib.h>

bool reverse_odd_even(int numbers[], int n);
int main(void)
{
    int numbers[] = {1,2,3,4,5};
    reverse_odd_even(numbers, 5);
    for(int i = 0; i < 5; ++i) {
        printf("%d ", numbers[i]);
    }
    printf("\n");

    int numbers_all_odd[] = {1,1,1,1,1};
    reverse_odd_even(numbers_all_odd, 5);
    for(int i = 0; i < 5; ++i) {
        printf("%d ", numbers_all_odd[i]);
    }
    printf("\n");

    int numbers_all_even[] = {2,2,2,2,2};
    reverse_odd_even(numbers_all_even, 5);
    for(int i = 0; i < 5; ++i) {
        printf("%d ", numbers_all_even[i]);
    }
    printf("\n");
}

bool reverse_odd_even(int numbers[], int n)
{
    if (NULL == numbers) {
        return false;
    }

    if (n <= 0) {
        return false;
    }

    int i = 0;
    int j = n - 1;

    while (i < j)
    {
        while(i < j && (numbers[i] & 0x1) == 1) ++i;
        while(i < j && (numbers[j] & 0x1) == 0) --j;
        if (i < j) {
            int tmp = numbers[i];
            numbers[i] = numbers[j];
            numbers[j] = tmp;
            ++i;
            --j;
        } else {
            break;
        }
    }

    return true;
}
