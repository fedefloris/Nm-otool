#ifndef OTOOL_H
# define OTOOL_H

# define WORD_NUM 16

# ifdef __APPLE__

#  define MAC_OBJ_HANDLER(x) mach_o_obj_handler(x)

# else

#  define MAC_OBJ_HANDLER(x) ERROR_LOG("Unrecognized format")

# endif

void      print_file_name(t_file *file, char *current_file);

#endif
