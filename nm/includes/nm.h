#ifndef NM_H
# define NM_H

# include "libft.h"
# include "ft_printf.h"
# include <stdlib.h>
# include <stdbool.h>
# include <sys/stat.h>

# define DEFAULT	"a.out"

# define BITS_32	32
# define BITS_64	64

typedef struct		s_file
{
	int				fd;
	struct stat		stat;

	void			*memory;

	int				format;
}					t_file;

typedef struct		s_nm
{
	int				argc;
	char			**argv;

	t_file			file;
}					t_nm;

void				config_nm(t_nm *nm, int argc, char **argv);
int					list_object_files_symbols(t_nm *nm);
int					list_object_file_symbols(t_nm *nm, char *file_name);

#endif
