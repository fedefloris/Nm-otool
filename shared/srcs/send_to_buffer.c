#include "nm_otool.h"

void		send_to_buffer(t_buffer *buffer, char *str)
{
	while (*str)
	{
		if (buffer->content_index >= BUFFER_SIZE)
			empty_the_buffer(buffer);
		buffer->content[buffer->content_index++] = *str++;
	}
}
