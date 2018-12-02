#include "nm_otool.h"
#include "nm.h"

static t_symbol	*merge(t_symbol *left, t_symbol *right, int (*cmp)())
{
	t_symbol	*curr;
	t_symbol	head;

	curr = &head;
	while (left && right)
	{
		if (cmp(left->name, right->name) <= 0)
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

static t_symbol	*get_middle_symbol(t_symbol *symbols)
{
	t_symbol *fast;
	t_symbol *slow;

	if (!symbols)
		return (NULL);
	slow = symbols;
	fast = symbols;
	while (fast->next && fast->next->next)
	{
		slow = slow->next;
		fast = fast->next->next;
	}
	return (slow);
}

static t_symbol	*merge_sort(t_symbol *head, int (*cmp)())
{
	t_symbol	*middle;
	t_symbol	*after_middle;

	middle = get_middle_symbol(head);
	after_middle = middle->next;
	middle->next = NULL;
	return (merge(merge_sort(head, cmp), merge_sort(after_middle,cmp), cmp));
}

void						sort_symbols(t_nm_otool *nm_otool, t_symbol **symbols)
{
	if (!*symbols || !(*symbols)->next || op(nm_otool, 'p'))
		return ;
	*symbols = merge_sort(*symbols, &ft_strcmp);
}
