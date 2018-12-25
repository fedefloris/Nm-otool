#include "nm_otool.h"
#include "otool.h"

void		print_file_name(t_nm_otool *nm_otool, char *current_file)
{
	if (IS_ARCHIVE(nm_otool->file.format))
	{
		if (!current_file)
			return ;
		ft_printf("%s(%s):\n", nm_otool->file.name, current_file);
	}
	else
		ft_printf("%s:\n", nm_otool->file.name);
}
