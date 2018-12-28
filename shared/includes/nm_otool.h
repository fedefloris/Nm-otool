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

# define DEFAULT_COLOR "\033[1;0m"
# define RED_COLOR "\033[1;31m"
# define YELLOW_COLOR "\033[1;33m"

# define ERROR_HEADER RED_COLOR "Error:" DEFAULT_COLOR
# define WARNING_HEADER YELLOW_COLOR "Warning:" DEFAULT_COLOR
# define ERROR_LOG(x) error_log(nm_otool->file.name, x)
# define WARNING_LOG(x) warning_log(nm_otool->file.name, x)

# define BAD_STRING_INDEX "bad string index"

# define MACH_O_FAT_32 1
# define MACH_O_FAT_64 2
# define MACH_O_32 3
# define MACH_O_64 4
# define ELF_32 5
# define ELF_64 6
# define ARCHIVE 7

# define FT_NM 1
# define FT_OTOOL 2

# define NM_OPTIONS "hrjp"
# define OTOOL_OPTIONS "t"

# define IS_MACH_O_FAT_32(x) x == MACH_O_FAT_32
# define IS_MACH_O_FAT_64(x) x == MACH_O_FAT_64
# define IS_MACH_O_FAT(x) (IS_MACH_O_FAT_32(x) || IS_MACH_O_FAT_64(x))

# define IS_MACH_O_32(x) x == MACH_O_32
# define IS_MACH_O_64(x) x == MACH_O_64
# define IS_MACH_O(x) (IS_MACH_O_32(x) || IS_MACH_O_64(x))

# define IS_ELF_32(x) x == ELF_32
# define IS_ELF_64(x) x == ELF_64
# define IS_ELF(x) (IS_ELF_32(x) || IS_ELF_64(x))

# define IS_ARCHIVE(x) x == ARCHIVE

# define SET(x, y) (x = (typeof(x))get_safe_address(nm_otool, (char*)y))
# define ADVANCE(x, y) ((char *)x != (char *)y && SET(x, y))
# define ADDRESS_IS_SAFE(x) get_safe_address(nm_otool, (char *)x)
# define STRUCT_IS_SAFE(x) get_safe_address(nm_otool, (char*)x + sizeof(*x) - 1)
# define STRING_IS_SAFE(x) string_is_safe(nm_otool, x)
# define NEXT_STRUCT(x) (SET(x, x + sizeof(*x)) && STRUCT_IS_SAFE(x))

# define LITTLE_ENDIAN_FILE 1
# define BIG_ENDIAN_FILE 2

# define SWAP(x, y) (typeof(x))endian_swap((uint64_t)x, sizeof(x), y)
# define SWAP_ENDIAN(x) SWAP(x, nm_otool->file.reversed_endian)
# define SWAP_ENDIAN_FORCE(x) SWAP(x, true)
# define MAX_ENDIAN_SWAP_SIZE sizeof(uint64_t)

# ifdef __APPLE__

#  define SET_FILE_INFO(x) set_file_info_on_macos(x)

# else

#  define SET_FILE_INFO(x) set_file_info_on_linux(x)

# endif

typedef struct		s_file
{
	char			*name;
	mode_t			mode;
	off_t			size;
	int				format;
	char			*memory;
	char			*end_of_file;
	bool			reversed_endian;
}					t_file;

typedef struct		s_nm_otool
{
	char			**argv;
	char			**env;
	unsigned long	options;
	unsigned char	routine;
	t_file			file;
	bool			print_file_name;
	char			bad_string_index[17];
}					t_nm_otool;

typedef bool		(*t_obj_handler)(t_nm_otool *);

bool				obj_handler(t_nm_otool *nm_otool);
bool				archive_handler(t_nm_otool *nm_otool);

bool				error_log(char *message, char *file_name);
bool				warning_log(char *message, char *file_name);

bool				config_nm_otool(t_nm_otool *nm_otool, char **argv,
						char **env, unsigned char routine);

int					list_objs_symbols(t_nm_otool *nm_otool,
						t_obj_handler obj_handler);
int					list_obj_symbols(t_nm_otool *nm_otool, char *file_name,
						t_obj_handler obj_handler);

char				*find_binary(t_nm_otool *nm_otool);

bool				set_file(t_nm_otool *nm_otool);
bool				set_file_info(t_nm_otool *nm_otool);
void				set_endianness(t_nm_otool *nm_otool,
						int file_endianness);
bool				unset_file(t_nm_otool *nm_otool);

bool				set_archive_format(t_nm_otool *nm_otool);
bool				set_file_info_on_linux(t_nm_otool *nm_otool);
bool				has_good_elf_magic_number(Elf32_Ehdr *header);

char				*get_safe_address(t_nm_otool *nm_otool, char *address);
bool				string_is_safe(t_nm_otool *nm_otool, char *str);

bool				options(char ***argv, char *valid_options,
						unsigned long *options);
bool				option_check(unsigned long options, char c);
bool				op(t_nm_otool *nm_otool, char c);

uint64_t			endian_swap(uint64_t value, size_t size,
						bool needs_reverse);

# ifdef __APPLE__

bool				set_file_info_on_macos(t_nm_otool *nm_otool);
bool				mach_o_fat_32(t_nm_otool *nm_otool);
bool				mach_o_fat_64(t_nm_otool *nm_otool);

bool				mach_o_obj_handler(t_nm_otool *nm_otool);
bool				mach_o_obj_handler_32(t_nm_otool *nm_otool);
bool				mach_o_obj_handler_64(t_nm_otool *nm_otool);

# endif

#endif
