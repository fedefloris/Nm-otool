#include "nm_otool.h"

bool    warning_log(char *message, char *file_name)
{
  ft_printf("%s %s: %s\n", ERROR_HEADER, message, file_name);
  return (false);
}
