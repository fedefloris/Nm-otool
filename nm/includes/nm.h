#ifndef NM_H
# define NM_H

# include "libft.h"
# include "ft_printf.h"
# include <stdlib.h>
# include <sys/stat.h>

typedef struct	s_nm
{
	int			argc;
	char		**argv;

	struct stat	stat;
}				t_nm;

int     list_object_files_symbols(t_nm *nm);
int     list_object_file_symbols(t_nm *nm, char *file_name);
#endif
