#ifndef NM_H
# define NM_H

# define DEFAULT_ARGUMENT	"a.out"

# ifdef __APPLE__

# define OBJ_HANDLER(x) mach_o_obj_handler(x)

# elif __linux__

# define OBJ_HANDLER(x) elf_obj_handler(x)

# else

# define OBJ_HANDLER(x) unknown_obj_handler(x)

# endif

bool			obj_handler(t_nm_otool *nm_otool);

typedef struct			s_symbol
{	
	char				*name;
	char				type;
	uint64_t			value;
	struct s_symbol		*next;
}						t_symbol;

# ifdef __APPLE__

typedef struct load_command
						t_lc;

typedef struct			s_section
{
	char				*name;
	uint8_t				sec_number;
	struct s_section	*next;
}						t_section;
bool			add_symbol(t_symbol **symbols, uint64_t n_value, char type, char *name);
void			display_symbols(t_nm_otool *nm_otool, t_symbol *symbols);
bool			free_sections(t_section *sections);
bool			free_symbols(t_symbol *symbols);
bool			mach_o_obj_handler(t_nm_otool *nm_otool);
bool			mach_o_32_obj_handler(t_nm_otool *nm_otool);
bool			mach_o_64_obj_handler(t_nm_otool *nm_otool);
t_symbol		*sort_symbols(t_nm_otool *nm_otool, t_symbol *symbols);

# elif __linux__

bool			elf_obj_handler(t_nm_otool *nm_otool);
bool			elf_32_obj_handler(t_nm_otool *nm_otool);
bool			elf_64_obj_handler(t_nm_otool *nm_otool);

# else

bool			unknown_obj_handler(t_nm_otool *nm_otool);

# endif

#endif
