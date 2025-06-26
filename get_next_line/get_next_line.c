#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*buf;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return ((void *)0);
	buf = read_line(fd, buf);
	if (!buf)
		return ((void *)0);
	line = extract_line(buf);
	buf = save_rest(buf);
	return (line);
}
