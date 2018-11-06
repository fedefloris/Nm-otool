#include "libft.h"

size_t  ft_lstsize(t_list *lst)
{
    t_list  *tmp;
    size_t  size;

    size = 0;
    if (lst != NULL)
    {
        tmp = lst;
        while (tmp != NULL)
        {
            tmp = (*tmp).next;
            size++;
        }
    }
    return (size);
}
