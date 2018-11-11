#ifndef NM_H
# define NM_H

# include "libft.h"
# include "ft_printf.h"
# include <stdlib.h>
# include <sys/stat.h>

# define FALSE	0
# define TRUE	1

typedef char		t_bool;

typedef struct		s_nm
{
	int				argc;
	char			**argv;

	int				fd;
	struct stat		stat;

	void			*memory;
}					t_nm;

int					list_object_files_symbols(t_nm *nm);
int					list_object_file_symbols(t_nm *nm, char *file_name);

#endif
