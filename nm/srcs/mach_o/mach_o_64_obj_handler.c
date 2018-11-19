#include "nm_otool.h"
#include "nm.h"

static void			print_nm(t_nm_otool *nm_otool, int nsyms, int symoff,  int stroff)
{
	int				i;
	char			*stringtable;
	struct nlist_64	*array;

	array = nm_otool->file.memory + symoff;
	stringtable = nm_otool->file.memory + stroff;
	i = 0;
	while (i < nsyms)
	{
		ft_printf("%s\n",stringtable + array[i].n_un.n_strx);
		i++;
	}
}

bool				mach_o_64_obj_handler(t_nm_otool *nm_otool)
{
	int						ncmds;
	int						i;
	struct mach_header_64	*header;
	struct load_command		*lc;
	struct symtab_command	*sym;

	header = (struct mach_header_64 *)nm_otool->file.memory;
	ncmds = header->ncmds;
	i = 0;
	lc = (void *)nm_otool->file.memory + sizeof(*header);
	while (i < ncmds)
	{
		if (lc->cmd == LC_SYMTAB)
		{
			sym = (struct symtab_command *) lc;
			print_nm(nm_otool, sym->nsyms, sym->symoff, sym->stroff);
			break ;
		}
		i++;
		lc = (void *)lc + lc->cmdsize;
	}
	return (true);
}
