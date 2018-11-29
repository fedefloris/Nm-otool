#include "nm_otool.h"
#include "nm.h"

bool				add_symbol(t_symbol **symbols, uint64_t n_value, char type, char *name)
{
	t_symbol		*new;
	t_symbol		*head;

	if (!(new = (t_symbol *)malloc(sizeof(t_symbol))))
	{
		free_symbols(*symbols);
		*symbols = NULL;
		return (false);
	}
	new->value = n_value;
	new->type = type;
	new->name = name;
	new->next = NULL;
	if (!*symbols)
		*symbols = new;
	else
	{
		head = *symbols;
		while (*symbols && (*symbols)->next)
			*symbols = (*symbols)->next;
		(*symbols)->next = new;
		*symbols = head;
	}
	return (true);
}