#ifndef NM_OTOOL_H
# define NM_OTOOL_H

# include "libft.h"
# include <stdlib.h>
# include <stdbool.h>
# include <sys/stat.h>

#ifdef __APPLE__
# include <mach-o/loader.h>
#endif

# define DEFAULT_ARGUMENT	"a.out"

# define BITS_32	32
# define BITS_64	64

typedef struct		s_file
{
	char			*name;
	off_t			size;
	void			*memory;
	int				format;
}					t_file;

typedef struct		s_nm_otool
{
	char			**env;

	t_file			*file;
}					t_nm_otool;

void				config_structure(t_nm_otool *nm_otool, char **env);
int					list_object_files_symbols(int argc, char **argv, char **env);
int					list_object_file_symbols(char *file_name, char **env);
char				*find_binary(t_file *file, char **env);

bool				set_mapped_file(t_file *file, char *file_name, char **env);
bool				set_file_format(t_file *file);

bool				unset_mapped_file(t_file *file);
#endif
