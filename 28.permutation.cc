#include <stdio.h>
#include <stdlib.h>
#include <string>

void permutation(char str[], int start, int end);
void swap(char str[], int i, int j);
int main(void)
{
    char str[] = "abcde";
    permutation(str, 0, strlen(str) - 1);
}

void permutation(char str[], int start, int end)
{
    if (start > end)
        return;

    if (start == end) {
        printf("%s\n", str);
    }

    for (int i = start; i <= end; i++) {
        swap(str, i, start);
        permutation(str, start + 1, end);
        swap(str, i, start);
    }
}

void swap(char str[], int i, int j)
{
    if (i==j) return;

    char tmp = str[i];
    str[i] = str[j];
    str[j] = tmp;
}
