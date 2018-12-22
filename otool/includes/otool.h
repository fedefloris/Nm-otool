#ifndef OTOOL_H
# define OTOOL_H

# define WORD_NUM 16

# ifdef __APPLE__

#  define MAC_OBJ_HANDLER(x) mach_o_obj_handler(x)

# else

#  define MAC_OBJ_HANDLER(x) ERROR_LOG("Unrecognized format")

# endif

bool      mach_o_obj_handler_32(t_nm_otool *nm_otool);
bool      mach_o_obj_handler_64(t_nm_otool *nm_otool);

void      print_file_name(t_file *file, char *current_file);

#endif
