#ifndef OTOOL_H
# define OTOOL_H

# include "libft.h"

# define SUCCESS 1
# define FAILURE 0

typedef struct  s_file
{
    size_t      file_size;
    char        *map;
}               t_file;

#endif
