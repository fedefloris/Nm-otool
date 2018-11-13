#ifndef OTOOL_H
# define OTOOL_H

# include "libft.h"

# define SUCCESS 1
# define FAILURE 0
# define WORD_NUM 16

typedef struct  s_file
{
    size_t      file_size;
    char        *map;
}               t_file;

/*
** load_file.c
*/
int             load_file(char *filename, t_file *file);

/*
** macho_64.c
*/
int             macho_64(t_file *file);

/*
** print.c
*/
void            print_64(unsigned char word);

#endif
