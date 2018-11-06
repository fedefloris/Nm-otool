#include "libft.h"

t_list  *ft_lst_search(t_list *lst, void *data, size_t n)
{
    t_list  *tmp;

    if (lst != NULL && data != NULL)
    {
        tmp = lst;
        while (tmp != NULL)
        {
            if (ft_memcmp(data, (*tmp).content, n) == 0)
                return (tmp);
            tmp = (*tmp).next;
        }
    }
    return (NULL);
}
