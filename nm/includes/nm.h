#ifndef NM_H
# define NM_H

# include "libft.h"
# include "ft_printf.h"
# include <stdlib.h>
# include <sys/stat.h>

# define FALSE		0
# define TRUE		1

# define BITS_32	32
# define BITS_64	64

typedef char		t_bool;

typedef struct		s_file
{
	int				fd;
	struct stat		stat;

	void			*memory;

	int				file_format;
}					t_file;

typedef struct		s_nm
{
	int				argc;
	char			**argv;

	t_file			file;
}					t_nm;

int					list_object_files_symbols(t_nm *nm);
int					list_object_file_symbols(t_nm *nm, char *file_name);

#endif
