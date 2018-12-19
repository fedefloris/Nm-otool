#ifndef OTOOL_H
# define OTOOL_H

# define FAT 10
# define WORD_NUM 16

/*
** archive.c
*/
bool      archive(t_file *file);

/*
** fat_64.c
*/
bool      fat(t_file *file);

/*
** macho_32.c
*/
bool      macho_32(t_file *file);

/*
** macho_64.c
*/
bool      macho_64(t_file *file);

/*
**  otool_obj_handler.c
*/
bool			otool_obj_handler(t_nm_otool *nm_otool);

/*
** print.c
*/
void      print_filename(t_file *file, char *current_file);

/*
** swap.c
*/
uint32_t  swap_endian(uint32_t value);

#endif
