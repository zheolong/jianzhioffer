#include <stdio.h>

double power(double base, int exp);
int main(void)
{
    printf("%lf \n", power(10, -1));
    printf("%lf \n", power(10, 0));
    printf("%lf \n", power(10, 1));
    printf("%lf \n", power(10, 2));
}

double power(double base, int exp)
{
    if (exp < 0)
        return (double)1.0 / power(base, -exp);

    if (exp == 0)
        return 1;
    
    double result = power(base, exp >> 1);
    result = result * result;
    if ((exp & 0x1) == 1) {
        result = result * base;
    }

    return result;
}
