#include<stdio.h>
bool get_least_numbers(int data[], int n, int k);
int patition(int data[], int start, int end);
int main(void)
{
    int data[] = {1,3,4,8,5,2};
    get_least_numbers(data,6,3);
    for (int i = 0; i < 6; i++) {
        printf("%d ", data[i]);
    }
}


bool get_least_numbers(int data[], int n, int k)
{
    if (data == NULL || n <=0 || k <= 0 || (k-n) > 1) {
        return false;
    }

    int start = 0;
    int end = n - 1;
    while(start < end)
    {
        int index = patition(data, start, end);
        if (index == (k-1)) {
            return true;
        } else if (index > (k-1)) {
            end = index - 1;
        } else {
            start = index + 1;
        }
    }
    return false;
}

int patition(int data[], int start, int end)
{
    int i = start;
    int j = end;
    int a = data[i];
    while (i < j) {
        while (i < j && data[j] > a)  j--;
        data[i] = data[j];
        while (i < j && data[i] < a)  i++;
        data[j] = data[i];
    }
    data[i] = a;

    return i;
}


