#include <stdio.h>
#include <stdlib.h>

int inverse_pairs(int data[], int copy[], int start, int end);
int main(void)
{
    int data[] = {7,5,6,4};
    int *copy = new int(4);
    int count = inverse_pairs(data, copy, 0, 3);
    printf("%d", count);
}

int inverse_pairs(int data[], int copy[], int start, int end)
{
    if (start == end) {
        copy[start] = data[start];
        return 0;
    }

    int mid = (start + end) >> 1;
    int n1 = inverse_pairs(copy, data, start, mid);
    int n2 = inverse_pairs(copy, data, mid + 1, end);
    
    int i = mid;
    int j = end;
    int index = end;
    int count = n1 + n2;
    while (i >= start && j >= (mid + 1)) {
        if (data[i] > data[j]) {
            copy[index--] = data[i--];
            count += j - mid;
        } else {
            copy[index--] = data[j--];
        }
    }

    for (; i >= start; --i) {
        copy[index--] = data[i];
    }
    
    for (; j >= mid + 1; --j) {
        copy[index--] = data[j];
    }

    return count;
}
