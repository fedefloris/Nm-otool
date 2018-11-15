#ifndef NM_OTOOL_H
# define NM_OTOOL_H

# include "libft.h"
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

int					list_object_files_symbols(int argc, char **argv);
int					list_object_file_symbols(char *file_name);

bool				set_mapped_file(t_file *file, char *file_name);
bool				set_file_format(t_file *file);

bool				unset_mapped_file(t_file *file);
#endif
