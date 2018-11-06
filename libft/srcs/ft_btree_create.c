#include <stdlib.h>
#include "libft.h"

t_btree   *ft_btree_create(void *item)
{
    t_btree *new;

    new = (t_btree *)malloc(sizeof(*new));
    if (new != NULL)
    {
        (*new).left = NULL;
        (*new).right = NULL;
        (*new).item = item;
    }
    return (new);
}
