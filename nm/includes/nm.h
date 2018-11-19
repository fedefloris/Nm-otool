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

# ifdef __APPLE__

bool			mach_o_obj_handler(t_nm_otool *nm_otool);
bool			mach_o_32_obj_handler(t_nm_otool *nm_otool);
bool			mach_o_64_obj_handler(t_nm_otool *nm_otool);

# elif __linux__

bool			elf_obj_handler(t_nm_otool *nm_otool);
bool			elf_32_obj_handler(t_nm_otool *nm_otool);
bool			elf_64_obj_handler(t_nm_otool *nm_otool);

# else

bool			unknown_obj_handler(t_nm_otool *nm_otool);

# endif

#endif
