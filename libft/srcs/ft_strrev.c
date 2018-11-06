#include "libft.h"

char    *ft_strrev(char *str)
{
    size_t  len;
    size_t  i;
    char    c;

    if (str != NULL && str[0] != '\0')
    {
        len = ft_strlen(str) - 1;
        i = 0;
        while (i < len)
        {
            c = str[len];
            str[len] = str[i];
            str[i] = c;
            i++;
            len--;
        }
    }
    return (str);
}
