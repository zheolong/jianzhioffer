#include <stdio.h>

long fibonacci(int n);
int main(void)
{
    for (int i = 0; i < 10; ++i)
        printf("%ld ", fibonacci(i));
}

long fibonacci(int n)
{
    if (n <= 2) {
        return n;
    }

    int b = 1;
    int a = 2;
    while (n > 2)
    {
        int tmp = a;
        a = a + b;
        b = tmp;
        --n;
    }
    
    return a;
}
