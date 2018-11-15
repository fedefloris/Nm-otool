#include "nm_otool.h"
#include <sys/mman.h>

bool      unset_mapped_file(t_file *file)
{
  if (munmap(file->memory, file->size) < 0)
    return (false);
  return (true);
}
