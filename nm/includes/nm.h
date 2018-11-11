#ifndef NM_H
# define NM_H

# include "libft.h"
# include "ft_printf.h"
# include <stdlib.h>

typedef struct	s_nm
{
	char		**argv;

	struct stat	stat;
}				t_nm;

int     list_object_files_symbols(int argc, char **argv);
int     list_object_file_symbols(char *file_name);
#endif
