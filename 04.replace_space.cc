#include <stdio.h>
#include <stdlib.h>
#include <exception>
#include <string.h>

#define MAX_LEN 100

bool replace_space(char *str, int capacity);
int main(int argc, char *argv[])
{
    char *str = (char *)malloc(MAX_LEN);
    strcpy(str, "  ab cd  ef  ");
    replace_space(str, MAX_LEN);
    printf("%s", str);
}

bool replace_space(char *str, int capacity)
{
    if (NULL == str) {
        return false;
    }

    char *p = str;
    int space_len = 0, orig_len = 0;
    while (*p != '\0') {
        if (*p == ' ')
            space_len++;

        orig_len++;
        p++;
    }

    int new_len = orig_len + 2*space_len;

    if (new_len + 1 > capacity) {
        return false;
    }

    int ol = orig_len;
    int nl = new_len;
    while (ol >= 0 && nl > ol) {
        if (str[ol] != ' ') {
            str[nl] = str[ol];
            --nl;
        } else {
            str[nl--] = '0';
            str[nl--] = '2';
            str[nl--] = '%';
        }
        --ol;
    }
    return true;
}
