#include "libft.h"

size_t ft_isprime(size_t n)
{
    size_t  i;

    if (n == 0 || n == 1)
        return (0);
    i = 2;
    while (i < n)
    {
        if ((n % i) == 0)
            return (0);
        i++;
    }
    return (1);
}
