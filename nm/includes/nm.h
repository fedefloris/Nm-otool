#ifndef NM_H
# define NM_H

# define DEFAULT_ARGUMENT	"a.out"
# define NM_OPTIONS "abc"

typedef struct			s_symbol
{
	char				*name;
	char				type;
	uint64_t			value;
	struct s_symbol		*next;
	struct s_symbol		*prev;
}						t_symbol;

bool			obj_handler(t_nm_otool *nm_otool);

bool			elf_obj_handler(t_nm_otool *nm_otool);

bool			elf_32_obj_handler(t_nm_otool *nm_otool);

bool			elf_64_obj_handler(t_nm_otool *nm_otool);
bool			elf_64_parse_section_headers(t_nm_otool *nm_otool,
	Elf64_Ehdr *header);
bool	   	elf_64_parse_section_header(t_nm_otool *nm_otool,
	Elf64_Shdr	*section_header, char *str_section);

bool			elf_64_set_symbols(t_nm_otool *nm_otool,Elf64_Shdr	*section_header,
	char *str_section, t_symbol **symbols);
char			elf_get_symbol_type(unsigned char st_info);

bool			add_symbol(t_symbol **symbols, uint64_t n_value,
	char type, char *name);
void			display_symbols(t_nm_otool *nm_otool, t_symbol *symbols);
bool			free_symbols(t_symbol *symbols);
void			sort_symbols(t_nm_otool *nm_otool, t_symbol **symbols);
t_symbol	*merge_sort_symbols(t_symbol *head, int (*cmp)());

# ifdef __APPLE__

# define MAC_OBJ_HANDLER(x) mach_o_obj_handler(x)

typedef struct load_command		t_lc;
typedef struct symtab_command	t_sym;

typedef struct			s_section
{
	char				*name;
	uint8_t				sec_number;
	struct s_section	*next;
}						t_section;

bool			free_sections(t_section *sections);
char			get_type(uint8_t n_type, uint64_t n_value, uint8_t n_sect,
	t_section *sections);

bool			mach_o_archive(t_nm_otool *nm_otool);
bool			mach_fat_32_obj_handler(t_nm_otool *nm_otool);
bool			mach_fat_64_obj_handler(t_nm_otool *nm_otool);

bool			mach_o_create_section(t_section **sections,
	char *sectname, unsigned char sec_number);

bool			mach_o_obj_handler(t_nm_otool *nm_otool);

bool			mach_o_32_obj_handler(t_nm_otool *nm_otool);
bool			mach_o_32_get_sections(t_nm_otool *nm_otool,
	t_section **sections, struct segment_command *segment, bool reset);

bool			mach_o_64_obj_handler(t_nm_otool *nm_otool);
bool			mach_o_64_get_sections(t_nm_otool *nm_otool,
	t_section **sections, struct segment_command_64 *segment, bool reset);
t_sym			*mach_o_read_load_commands(t_nm_otool *nm_otool,
	t_lc *lc, t_section **sections, int number_of_commands);

# else

# define MAC_OBJ_HANDLER(x) ERROR_LOG("Unrecognized format")

# endif

#endif
