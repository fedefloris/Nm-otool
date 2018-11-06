#include "libft.h"

void    ft_btree_prefix(t_btree *root, void (*f) (void *))
{
    t_btree *tmp;

    tmp = root;
    if (root != NULL)
        f((*tmp).item);
    else if ((*tmp).left != NULL)
        ft_btree_prefix((t_btree *)(*tmp).left, f);
    else if ((*tmp).right != NULL)
        ft_btree_prefix((t_btree *)(*tmp).right, f);
}
