#include<stdio.h>

int more_than_half(int data[], int n);
int main(void)
{
    int data[] = {1,2,1,1,1,1,2,1,2,2};
    printf("%d ",more_than_half(data, 10));
}

int more_than_half(int data[], int n)
{
    if (data == NULL || n <= 0)
        return 0;

    int i = 0;
    int num = 0;
    int d = data[0];
    while (i < n)
    {
        if (num == 0) {
            d = data[i];
            num = 1;
        } else if (data[i] == d) {
            num++;
        } else {
            num--;
        }
        i++;
    }

    // TODO: check if more than half
    
    return d;
}
