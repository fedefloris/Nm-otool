#ifndef OTOOL_H
# define OTOOL_H

# define WORD_NUM 16

/*
** mach_o_obj_handler_32.c
*/
bool      mach_o_obj_handler_32(t_nm_otool *nm_otool);

/*
** mach_o_obj_handler_64.c
*/
bool      mach_o_obj_handler_64(t_nm_otool *nm_otool);

/*
**  obj_handler.c
*/
bool			obj_handler(t_nm_otool *nm_otool);

/*
** print.c
*/
void      print_filename(t_file *file, char *current_file);

/*
** swap.c
*/
uint32_t  swap_endian(uint32_t value);

#endif
