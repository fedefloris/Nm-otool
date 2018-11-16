#ifndef NM_OTOOL_H
# define NM_OTOOL_H

# include "libft.h"
# include <stdlib.h>
# include <stdbool.h>
# include <sys/stat.h>
# include <sys/types.h>

# define DEFAULT_ARGUMENT	"a.out"

# define MAC_O_32_FORMAT	1
# define MAC_O_64_FORMAT	2
# define ELF_32_FORMAT 3
# define ELF_64_FORMAT 4

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

	t_file			file;
}					t_nm_otool;

int					list_object_files_symbols(int argc, char **argv, char **env);
int					list_object_file_symbols(t_nm_otool *nm_otool, char *file_name);
void				config_structure(t_nm_otool *nm_otool, char **env);
char				*find_binary(t_nm_otool *nm_otool);

bool				set_mapped_file(t_nm_otool *nm_otool);
bool				set_file_format(t_nm_otool *nm_otool);

#ifdef __APPLE__
bool				set_mac_o_format(t_nm_otool *nm_otool);
#elif __linux__
bool				set_elf_format(t_nm_otool *nm_otool);
#endif

bool				unset_mapped_file(t_nm_otool *nm_otool);
#endif
