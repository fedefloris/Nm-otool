#ifndef NM_H
# define NM_H

# define DEFAULT_ARGUMENT	"a.out"

bool			obj_handler(t_nm_otool *nm_otool);

#ifdef __APPLE__
bool			mach_o_32_obj_handler(t_nm_otool *nm_otool);
bool			mach_o_64_obj_handler(t_nm_otool *nm_otool);
#elif __linux__
bool			elf_32_obj_handler(t_nm_otool *nm_otool);
bool			elf_64_obj_handler(t_nm_otool *nm_otool);
#endif

#endif
