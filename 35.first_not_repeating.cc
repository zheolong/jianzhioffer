#include <stdio.h>
#include <stdlib.h>
#include <string>

char first_not_repeating(const char *str);
int main(void)
{
    char f = first_not_repeating("abbacedf");
    if (f != 0)
        printf("%c", f);
}

char first_not_repeating(const char *str)
{
    int n = strlen(str);
    int *numbers = (int *)malloc(sizeof(int)*256);
    bzero(numbers, n);
    for (int i = 0; i < n; i++) {
        numbers[str[i]]++;
    }
    for (int i = 0; i < 256; i++) {
        if (numbers[i] == 1)
            return i;
    }
    return 0;
}
