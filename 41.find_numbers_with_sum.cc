#include<stdio.h>
#include<stdlib.h>
#include<string>

bool find_numbers_with_sum(char data[], int n, int sum, int* index1, int* index2);
void print_seq_with_sum(int sum);

int main(void)
{
    char data[] = {1, 2, 4, 7, 11, 15};
    int index1;
    int index2;
    if (find_numbers_with_sum(data, 6, 15, &index1, &index2))
        printf("%d, %d\n", index1, index2);

    print_seq_with_sum(15);
}

bool find_numbers_with_sum(char data[], int n, int sum, int* index1, int* index2)
{
    if (data == NULL || n <= 1 || index1 == NULL || index2 == NULL)
        return false;

    int i = 0;
    int j = n-1;

    while (i <= n-1 && j >=0) {
        if (data[i] + data[j] == sum) {
            *index1 = i;
            *index2 = j;
            return true;
        } else if (data[i] + data[j] > sum) {
            j--;
        } else {
            i++;
        }
    }

    return false;
}

void print_seq_with_sum(int sum)
{
    if (sum <= 0)
        return;

    int start = 1;
    int end = 2;
    int cur = start + end;
    while (start < end) {
        if (cur == sum) {
            printf("(%d,%d) ", start, end);
            cur -= start;
            start++;
        } else if (cur > sum) {
            cur -= start;
            start++;
        } else {
            end++;
            cur += end;
        }
    }
}
