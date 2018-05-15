#include <stdio.h>

int number_of_one(int n);
int main(void)
{
    for (int i = 0; i < 10; ++i)
        printf("%d ", number_of_one(i));
}

int number_of_one(int n)
{
    int count = 0;
    while (n)
    {
        ++count;
        n = n & (n-1); 
    }
    return count;
}
