#include "nm_otool.h"
#include "otool.h"

void		print_file_name(t_file *file, char *current_file)
{
	if (IS_ARCHIVE(file->format))
	{
		if (!current_file)
			return ;
		ft_printf("%s(%s):\n", file->name, current_file);
	}
	else
		ft_printf("%s:\n", file->name);
}
