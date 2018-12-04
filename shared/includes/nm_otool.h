#ifndef NM_OTOOL_H
# define NM_OTOOL_H

# include "libft.h"
# include "ft_printf.h"
# include <ar.h>
# include <stdint.h>
# include <stdlib.h>
# include <stdbool.h>
# include <sys/stat.h>
# include <sys/types.h>

# ifdef __APPLE__

#  include <mach-o/loader.h>
#  include <mach/machine.h>
#  include <mach-o/nlist.h>
#  include <mach-o/fat.h>
#  include "elf.h"

# else

#  include <elf.h>

# endif

# define NM_OPTIONS "abc"

# define DEFAULT_COLOR "\033[1;0m"
# define RED_COLOR "\033[1;31m"
# define YELLOW_COLOR "\033[1;33m"

# define ERROR_HEADER RED_COLOR "Error:" DEFAULT_COLOR
# define WARNING_HEADER YELLOW_COLOR "Warning:" DEFAULT_COLOR
# define ERROR_LOG(x) error_log(nm_otool->file.name, x)
# define WARNING_LOG(x) warning_log(nm_otool->file.name, x)

# define MACH_O_FAT_32 1
# define MACH_O_FAT_64 2
# define MACH_O_ARCHIVE 3
# define MACH_O_32 4
# define MACH_O_64 5
# define ELF_32 6
# define ELF_64 7

# define IS_ELF_32(x) x & ELF_32
# define IS_ELF_64(x) x & ELF_64
# define IS_ELF(x) IS_ELF_32(x) || IS_ELF_64(x)

# define LITTLE_ENDIAN_TYPE 1
# define BIG_ENDIAN_TYPE 2

# define SET(x,y) (x = (typeof(x))get_safe_address(nm_otool, (char *)y))
# define STRUCT_IS_SAFE(x) get_safe_address(nm_otool, (char *)x + sizeof(*x) - 1)
# define NEXT_STRUCT(x) SET(x, x + sizeof(*x)) && STRUCT_IS_SAFE(x)

# ifdef __APPLE__

# define SET_FILE_INFO(x) set_file_info_on_macos(x)

# else

# define SET_FILE_INFO(x) set_file_info_on_linux(x)

# endif

typedef struct		s_file
{
	char			*name;
	off_t			size;
	mode_t			mode;
	char			*memory;
	char			*end_of_file;
	int				format;
	int				endianness;
}					t_file;

typedef struct		s_nm_otool
{
	char			**argv;
	char			**env;
	unsigned long	options;
	bool			print_file_name;
	t_file			file;
}					t_nm_otool;

typedef bool		(*t_obj_handler)(t_nm_otool *);

bool				error_log(char *message, char *file_name);
bool				warning_log(char *message, char *file_name);

bool				config_nm_otool(t_nm_otool *nm_otool,
		char **argv, char **env);

int					list_objs_symbols(t_nm_otool *nm_otool,
		t_obj_handler obj_handler);
int					list_obj_symbols(t_nm_otool *nm_otool, char *file_name,
		t_obj_handler obj_handler);

char				*find_binary(t_nm_otool *nm_otool);

bool				set_file(t_nm_otool *nm_otool);
bool				set_file_info(t_nm_otool *nm_otool);

bool				set_file_info_on_linux(t_nm_otool *nm_otool);
bool				has_good_ELF_magic_number(Elf32_Ehdr *header);

char				*get_safe_address(t_nm_otool *nm_otool, char *address);
bool				string_is_safe(t_nm_otool *nm_otool, char *str);

bool				options(char ***argv, char *valid_options, unsigned long *options);
bool				option_check(unsigned long options, char c);
bool				op(t_nm_otool *nm_otool , char c);

# ifdef __APPLE__

bool				set_file_info_on_macos(t_nm_otool *nm_otool);

# endif

bool				unset_file(t_nm_otool *nm_otool);

#endif
