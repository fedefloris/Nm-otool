#ifndef OTOOL_H
# define OTOOL_H

# define BYTES_PER_ROW 16

# ifdef __APPLE__

#  define MAC_OBJ_HANDLER(x) mach_o_obj_handler(x)

# else

#  define MAC_OBJ_HANDLER(x) ERROR_LOG("Unrecognized format")

# endif

void      print_file_name(t_nm_otool *nm_otool, char *current_file);
void		print_row(unsigned char *byte);

#endif
