#include<stdio.h>

bool valid = true;

int greast_sum_of_subarray(int data[], int n);
void greast_sum_of_subarray_with_dynamic_programming(int data[], int n, int *max, int *max_tail);
int main(void)
{
    int data[] = {-1, 1, -2, 2, 3, -2, -2, 8};
    int n = 8;
    int max = greast_sum_of_subarray(data, n);
    if (valid) {
        printf("%d\n", max);
    }
    
    int max2;
    int max_tail;
    valid = true;
    greast_sum_of_subarray_with_dynamic_programming(data, n, &max2, &max_tail);
    if (valid) {
        printf("%d\n", max2);
    }
}

int greast_sum_of_subarray(int data[], int n)
{
    if (data == NULL || n <= 0) {
        valid = false;
        return -1;
    }

    int max = data[0];
    int cur = data[0];
    
    int i = 1;
    while(i < n)
    {
        cur = cur + data[i];
        max = cur > max ? cur: max;
        if (cur <= 0) {
            cur = data[i];
        }
        i++;
    }
    return max;
}

void greast_sum_of_subarray_with_dynamic_programming(int data[], int n, int *max, int *max_tail)
{
    if (data == NULL || n <= 0) {
        valid = false;
        return;
    }

    if (n - 1 == 0) {
        *max = data[n-1];
        *max_tail = data[n-1];
    } else {
        int max_tmp;
        int max_tail_tmp;
        greast_sum_of_subarray_with_dynamic_programming(data, n - 1, &max_tmp, &max_tail_tmp);
        *max_tail = (max_tail_tmp + data[n - 1]) > data[n-1] ? (max_tail_tmp + data[n - 1]): data[n-1];
        *max = *max_tail > max_tmp ? *max_tail: max_tmp;
    }
}
