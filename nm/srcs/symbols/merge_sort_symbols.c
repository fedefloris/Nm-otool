#include "nm_otool.h"
#include "nm.h"

static t_symbol	*merge(t_symbol *left, t_symbol *right, int (*cmp)())
{
	t_symbol	*curr;
	t_symbol	head;

	curr = &head;
	while (left && right)
	{
		if (cmp(left, right) <= 0)
		{
			curr->next = left;
			left = left->next;
		}
		else
		{
			curr->next = right;
			right = right->next;
		}
		curr = curr->next;
	}
	curr->next = (!left) ? right : left;
	return (head.next);
}

static t_symbol	*merge_sort(t_symbol *head, int (*cmp)())
{
	t_symbol	*middle;
	t_symbol	*after_middle;

	if (!head || !head->next)
		return (head);
	middle = get_middle_symbol(head);
	after_middle = middle->next;
	middle->next = NULL;
	return (merge(merge_sort(head, cmp), merge_sort(after_middle,cmp), cmp));
}

t_symbol		*merge_sort_symbols(t_symbol *head, int (*cmp)())
{
	return (merge_sort(head, cmp));
}
