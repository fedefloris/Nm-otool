#ifndef NM_OTOOL_H
# define NM_OTOOL_H

# include "libft.h"
# include <stdlib.h>
# include <stdbool.h>
# include <sys/stat.h>
# include <sys/types.h>

# define MACH_O_32_FORMAT	1
# define MACH_O_64_FORMAT	2
# define ELF_32_FORMAT 3
# define ELF_64_FORMAT 4

# define LITTLE_ENDIAN_TYPE 1
# define BIG_ENDIAN_TYPE 2

typedef struct		s_file
{
	char		*name;
	off_t		size;
	void		*memory;
	int			format;
	int			endianness;
}									t_file;

typedef struct		s_nm_otool
{
	char			**argv;
	char			**env;
	t_file		file;
}									t_nm_otool;

typedef bool	(*t_obj_handler)(t_nm_otool *);

void			config_nm_otool(t_nm_otool *nm_otool, char **argv, char **env);

int				list_objs_symbols(t_nm_otool *nm_otool, t_obj_handler obj_handler);
int				list_obj_symbols(t_nm_otool *nm_otool, char *file_name,
	t_obj_handler obj_handler);

char			*find_binary(t_nm_otool *nm_otool);

bool			set_file(t_nm_otool *nm_otool);
bool			set_file_info(t_nm_otool *nm_otool);

#ifdef __APPLE__
bool			set_mach_o_info(t_nm_otool *nm_otool);
#elif __linux__
bool			set_elf_info(t_nm_otool *nm_otool);
#endif

bool			unset_mapped_file(t_nm_otool *nm_otool);
#endif
