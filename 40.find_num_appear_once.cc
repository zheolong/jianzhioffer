#include <stdio.h>

bool find_nums_appear_once(int data[], int n, int* number1, int* number2);
int main(void)
{
    int data[] = {1,2,3,5,1,4,4,2};
    int n = 8;
    int number1;
    int number2;
    if (find_nums_appear_once(data, n, &number1, &number2)) {
        printf("%d,%d", number1,number2);
    }
}

bool find_nums_appear_once(int data[], int n, int* number1, int* number2)
{
    if (data == NULL || n <= 1) {
        return false;
    }

    int tmp = data[0];
    for (int i = 1; i < n; i++) {
        tmp ^= data[i];
    }

    int mark = 1;
    while (tmp > 0 && ((tmp & 0x1) == 0)) {
        tmp = tmp >> 1;
        mark = mark << 1;
    }

    int *data1 = new int[n];
    int *data2 = new int[n];
    int n1 = 0;
    int n2 = 0;
    for (int i = 0; i < n; i++) {
        if ((data[i] & mark) == mark) {
            data1[n1++] = data[i];
        } else {
            data2[n2++] = data[i];
        }
    }

    *number1 = data1[0];
    for (int i = 1; i < n1; i++) {
        *number1 ^= data1[i];
    }

    *number2 = data2[0];
    for (int i = 1; i < n2; i++) {
        *number2 ^= data2[i];
    }
    return true;
}
