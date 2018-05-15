#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int main(int argc, char *argv[])
{
    printf("%ld", strtol("0x11", NULL, 0));
    printf("%ld", strtol("-0x11", NULL, 0));
}

static inline int 
isupper (char c)
{
    return (c >= 'A' && c <= 'Z');
}

static inline int 
isalpha (char c)
{
    return ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'));
}

static inline int 
isdigit (char c)
{
    return (c >= '1' && c <= '9');
}

static inline int 
isspace (char c)
{
    return (c == ' ' || c == '\t' || c == '\n' || c == '\12');
}

long strtol(const char *nptr, char **endptr, register int base)
{
    register const char *s = nptr;
    register unsigned long acc;
    register int c;
    register unsigned long cutoff;
    register int neg = 0, any, cutlim;

    /* skip space */
    do {
        c = *s++;
    } while (isspace(c));

    /* check +/- sign */
    if (c == '-') {
        neg = 1;
        c = *s++;
    } else if (c == '+') {
        c = *s++;
    }

    /* check if base 16 */
    if ((base == 0 || base == 16) && c == '0' && (*s == 'x' || *s == 'X')) {
        c = s[1];
        s += 2;
        base = 16;
    } else if ((base == 0 || base == 2) && c == '0' && (*s == 'b' || *s == 'B')) {
        c = s[1];
        s += 2;
        base = 2;
    } else if (base == 0) {
        base = c == '0' ? 8 : 10;
    }

    /* */

    cutoff = neg ? -(unsigned long)LONG_MIN : LONG_MAX;
    cutlim = cutoff % (unsigned long)base;
    cutoff /= (unsigned long)base;
    for (acc = 0, any = 0;; c = *s++) {
        if (isdigit(c))
            c -= '0';
        else if (isalpha(c))
            c -= isupper(c) ? 'A' - 10 : 'a' - 10;
        else 
            break;

        if (c >= base)
            break;

        if (any < 0 || acc > cutoff || (acc == cutoff && c > cutlim))
            any = -1;
        else {
            any = 1;
            acc *= base;
            acc += c;
        }
    }

    if (any < 0) 
        acc = neg ? LONG_MIN: LONG_MAX;
    else if (neg)
        acc = -acc;

    if (endptr != 0)
        *endptr = (char *)(any ? s - 1 : nptr);

    return acc;
}
