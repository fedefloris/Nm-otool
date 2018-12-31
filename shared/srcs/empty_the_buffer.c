#include "nm_otool.h"
#include <unistd.h>

void		empty_the_buffer(t_buffer *buffer)
{
	write(1, buffer->content, buffer->content_index);
	config_buffer(buffer);
}
