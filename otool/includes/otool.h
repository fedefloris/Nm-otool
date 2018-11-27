#ifndef OTOOL_H
# define OTOOL_H

# include <mach-o/fat.h>
# include "libft.h"

# define SUCCESS 1
# define FAILURE 0
# define WORD_NUM 16
# define ARCHIVE 'a'
# define FAT 'f'

typedef struct  s_file
{
    size_t      file_size;
    char        *map;
    char        *filename;
    char        filetype;
}               t_file;

/*
** archive.c
*/
int             archive(t_file *file);

/*
** fat_64.c
*/
int             fat(t_file *file);

/*
** load_file.c
*/
int             load_file(char *filename, t_file *file);

/*
** macho_32.c
*/
int             macho_32(t_file *file);

/*
** macho_64.c
*/
int             macho_64(t_file *file);

/*
**  otool.c
*/
int             otool(t_file *file);

/*
** print.c
*/
void            print_filename(t_file *file, char *current_file);

/*
** swap.c
*/
uint32_t    swap_endian(uint32_t value);

#endif
