#include "nm_otool.h"
#include "nm.h"

static t_symbol	*create_symbol(uint64_t n_value, char type,
	char *name)
{
	t_symbol		*new;

	if (!(new = (t_symbol *)ft_memalloc(sizeof(t_symbol))))
		return (NULL);
	new->value = n_value;
	new->type = type;
	new->name = name;
	return (new);
}

static void 	append_to_symbols(t_symbol **symbols,
	t_symbol *new)
{
	if (!*symbols)
	{
		*symbols = new;
		(*symbols)->last = new;
	}
	else
	{
		(*symbols)->last->next = new;
		(*symbols)->last = new;
	}
}

bool			add_symbol(t_symbol **symbols,
	uint64_t n_value, char type, char *name)
{
	t_symbol		*new;

	if (!(new = create_symbol(n_value, type, name)))
	{
		free_symbols(*symbols);
		*symbols = NULL;
		return (false);
	}
	append_to_symbols(symbols, new);
	return (true);
}
