#include "nm_otool.h"
#include "nm.h"

bool				mach_o_64_obj_handler(t_nm_otool *nm_otool)
{
	int						ncmds;
	int						i;
	struct mach_header_64	*header;
	struct load_command		*lc;

	header = (struct mach_header_64 *)nm_otool->file.memory;
	ncmds = header->ncmds;
	i = 0;
	lc = (void *)nm_otool->file.memory + sizeof(*header);
	while (i < ncmds)
	{
		if (lc->cmd == LC_SYMTAB)
		{
			break ;
		}
		lc = (void *)lc + lc->cmdsize;
	}

	ft_printf("Mach-o-64, File_name: %s\n", nm_otool->file.name);
	return (true);
}
