#include <stdio.h>
#include <stdlib.h>

void print(int *number, int n);
void print_to_max(int *number, int len, int index);
int main(void)
{
    int n = 3;
    int *number = (int *)malloc(sizeof(int) * n);
    print_to_max(number, n, 0);
}

void print_to_max(int *number, int len, int index)
{
    if (index > len - 1) {
        print(number, len);
        return;
    }

    for(int i = 0; i < 10; ++i) {
        number[index] = i;
        print_to_max(number, len, index + 1); 
    }

    return;
}

void print(int *number, int n)
{
    bool printed = false;

    int first;
    for (first = 0; first < n && number[first] == 0; ++first) { }

    for(int i = first; i < n; i++)
    {
        printf("%d", number[i]);
        printed = true;
    }

    if (!printed)
        printf("0");


    printf("\n");
}
