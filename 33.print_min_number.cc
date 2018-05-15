#include <stdio.h>
#include <string>
#include <stdlib.h>

#define g_max_number_len 10

char* g_str_combine1 = new char[g_max_number_len * 2 + 1];
char* g_str_combine2 = new char[g_max_number_len * 2 + 1];

void print_min_number(int *numbers, int len);
int compare(const void *str_number1, const void *str_number2);
int main(void)
{
    int numbers[] = {3,32,321};
    print_min_number(numbers, 3);
}

void print_min_number(int *numbers, int len)
{
    if (NULL == numbers || len <= 0) {
        return;
    }

    char **str_numbers = (char **)malloc(sizeof(char *)*len);
    for (int i = 0; i < len; i++) {
        str_numbers[i] = (char *)malloc(sizeof(char)*(g_max_number_len + 1));
        sprintf(str_numbers[i], "%d", numbers[i]);
    }

    qsort(str_numbers, len, sizeof(char *), compare);

    for (int i = 0; i < len; i++) {
        printf("%s", str_numbers[i]);
    }
}

int compare(const void *str_number1, const void *str_number2)
{
    strcpy(g_str_combine1, *(const char **)str_number1);
    strcat(g_str_combine1, *(const char **)str_number2);

    strcpy(g_str_combine2, *(const char **)str_number2);
    strcat(g_str_combine2, *(const char **)str_number1);

    return strcmp(g_str_combine1, g_str_combine2);
}
