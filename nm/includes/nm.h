#ifndef NM_H
# define NM_H

# define DEFAULT_ARGUMENT	"a.out"

typedef struct		s_symbol
{
	char			*name;
	char			type;

	struct s_symbol	*next;
	struct s_symbol	*last;
	uint64_t		value;
}					t_symbol;

typedef struct		s_elf_symbols_info
{
	char			*header_str_section;
	char			*str_section;
	char			*sh_name;

	t_symbol		*symbols;
	uint16_t		index;

	uint16_t		st_shndx;
	uint32_t		sh_type;
	uint32_t		sh_flags;
	unsigned char	st_info;
}					t_elf_symbols_info;

int					display_usage(void);

bool				elf_obj_handler(t_nm_otool *nm_otool);

bool				elf_obj_handler_32(t_nm_otool *nm_otool);
bool				elf_parse_section_headers_32(t_nm_otool *nm_otool,
						Elf32_Ehdr *header);
bool				elf_parse_section_header_32(t_nm_otool *nm_otool,
						Elf32_Shdr	*section_header, t_elf_symbols_info *info);
bool				elf_set_symbols_32(t_nm_otool *nm_otool,
						Elf32_Shdr	*section_header, t_elf_symbols_info *info);

bool				elf_obj_handler_64(t_nm_otool *nm_otool);
bool				elf_parse_section_headers_64(t_nm_otool *nm_otool,
						Elf64_Ehdr *header);
bool				elf_parse_section_header_64(t_nm_otool *nm_otool,
						Elf64_Shdr	*section_header, t_elf_symbols_info *info);
bool				elf_set_symbols_64(t_nm_otool *nm_otool,
						Elf64_Shdr	*section_header, t_elf_symbols_info *info);

char				elf_get_type(t_elf_symbols_info	*info);
char				elf_get_type_from_section(t_elf_symbols_info *info);
char				elf_get_type_from_flags(t_elf_symbols_info *info);

bool				add_symbol(t_symbol **symbols, uint64_t n_value,
						char type, char *name);

void				sort_symbols(t_nm_otool *nm_otool, t_symbol **symbols);
t_symbol			*merge_sort_symbols(t_symbol *head, int (*cmp)());
t_symbol			*get_middle_symbol(t_symbol *symbols);

void				display_symbols(t_nm_otool *nm_otool, t_symbol *symbols);
void				display_symbol(t_nm_otool *nm_otool, t_symbol *sym);

bool				free_symbols(t_symbol *symbols);

# ifdef __APPLE__

#  define MAC_OBJ_HANDLER(x) mach_o_obj_handler(x)

typedef struct load_command		t_lc;
typedef struct symtab_command	t_sym;

typedef struct		s_reader
{
	uint8_t			**sections;
	t_symbol		*symbols;
	t_sym			*symtab;
}					t_reader;

bool				mach_o_archive(t_nm_otool *nm_otool);

bool				mach_o_get_sections_32(t_nm_otool *nm_otool,
						uint8_t **sections, struct segment_command *segment,
						bool reset);
bool				mach_o_get_sections_64(t_nm_otool *nm_otool,
						uint8_t **sections, struct segment_command_64 *segment,
						bool reset);

t_sym				*mach_o_read_load_commands(t_nm_otool *nm_otool,
						t_lc *lc, uint8_t **sections, int number_of_commands);

char				mach_o_get_type(uint8_t n_type,
						uint64_t n_value, uint8_t n_sect,
						uint8_t **sections);
bool				mach_o_free_sections(uint8_t **sections);

# else

#  define MAC_OBJ_HANDLER(x) ERROR_LOG("Unrecognized format")

# endif

#endif
