#ifndef OTOOL_H
# define OTOOL_H

# include <mach-o/fat.h>
# include "libft.h"

# define SUCCESS 1
# define FAILURE 0
# define WORD_NUM 16
# define ARCHIVE 'a'
# define FAT 'f'

typedef struct  s_file2
{
    size_t      file_size;
    char        *map;
    char        *filename;
    char        filetype;
}               t_file2;

/*
** archive.c
*/
int             archive(t_file2 *file);

/*
** fat_64.c
*/
int             fat(t_file2 *file);

/*
** load_file.c
*/
int             load_file(char *filename, t_file2 *file);

/*
** macho_32.c
*/
int             macho_32(t_file2 *file);

/*
** macho_64.c
*/
int             macho_64(t_file2 *file);

/*
**  otool.c
*/
int             otool(t_file2 *file);

/*
** print.c
*/
void            print_filename(t_file2 *file, char *current_file);

/*
** swap.c
*/
uint32_t    swap_endian(uint32_t value);

#endif
