#ifndef NM_OTOOL_H
# define NM_OTOOL_H

# include "libft.h"
# include "ft_printf.h"
# include <stdlib.h>
# include <stdbool.h>
# include <sys/stat.h>
# include <sys/types.h>

# ifdef __APPLE__
#  include <mach-o/loader.h>
#  include <mach-o/nlist.h>
# endif

# define DEFAULT_COLOR "\033[1;0m"
# define RED_COLOR "\033[1;31m"
# define YELLOW_COLOR "\033[1;33m"

# define ERROR_HEADER RED_COLOR "Error:" DEFAULT_COLOR
# define WARNING_HEADER YELLOW_COLOR "Warning:" DEFAULT_COLOR
# define ERROR_LOG(x) ft_printf("%s %s\n", ERROR_HEADER, x)
# define WARNING_LOG(x) ft_printf("%s %s\n", WARNING_HEADER, x)

# define LITTLE_ENDIAN_TYPE 1
# define BIG_ENDIAN_TYPE 1

# define MACH_O_32_FORMAT	1
# define MACH_O_64_FORMAT	2
# define ELF_32_FORMAT 3
# define ELF_64_FORMAT 4

# ifdef __APPLE__

# define SET_FILE_INFO(x) set_mach_o_info(x)

# elif __linux__

# define SET_FILE_INFO(x) set_elf_info(x)

# else

# define SET_FILE_INFO(x) set_unknown_info(x)

# endif

typedef struct		s_file
{
<<<<<<< HEAD
=======
<<<<<<< HEAD
=======
<<<<<<< HEAD
>>>>>>> Added mach-o header.
	char			*name;
	off_t			size;
	mode_t			mode;
	void			*memory;
	int				format;
	int				endianness;
}					t_file;
<<<<<<< HEAD
=======
=======
>>>>>>> Added mach-o header.
	char		*name;
	off_t		size;
	mode_t		mode;
	void		*memory;
	int			format;
	int			endianness;
}									t_file;
<<<<<<< HEAD
=======
>>>>>>> Added mach-o header.
>>>>>>> Added mach-o header.
>>>>>>> Added mach-o header.

typedef struct		s_nm_otool
{
	char			**argv;
	char			**env;
	t_file			file;
}					t_nm_otool;

typedef bool		(*t_obj_handler)(t_nm_otool *);

void				config_nm_otool(t_nm_otool *nm_otool,
		char **argv, char **env);

int					list_objs_symbols(t_nm_otool *nm_otool,
		t_obj_handler obj_handler);
int					list_obj_symbols(t_nm_otool *nm_otool, char *file_name,
		t_obj_handler obj_handler);

char				*find_binary(t_nm_otool *nm_otool);

bool				set_file(t_nm_otool *nm_otool);
bool				set_file_info(t_nm_otool *nm_otool);

# ifdef __APPLE__

bool				set_mach_o_info(t_nm_otool *nm_otool);

# elif __linux__

bool				set_elf_info(t_nm_otool *nm_otool);

# else

bool				set_unknown_info(t_nm_otool *nm_otool);

# endif

bool				unset_file(t_nm_otool *nm_otool);

#endif
