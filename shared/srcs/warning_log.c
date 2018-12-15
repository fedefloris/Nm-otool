#include "nm_otool.h"

bool	warning_log(char *message, char *file_name)
{
	ft_putstr_fd(WARNING_HEADER, 2);
	ft_putstr_fd(" ", 2);
	ft_putstr_fd(message, 2);
	ft_putstr_fd(": ", 2);
	ft_putendl_fd(file_name, 2);
	return (false);
}
