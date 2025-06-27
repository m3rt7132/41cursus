#include "get_next_line.h"

char	*ft_strdup(const char *s)
{
	int		len;
	int		i;
	char	*dup;

	len = 0;
	while (s[len])
		len++;
	dup = (char *) malloc(sizeof(char) * (len + 1));
	if (dup == NULL)
		return ((void *)0);
	i = 0;
	while (i < len)
	{
		dup[i] = s[i];
		i++;
	}
	dup[i] = 0;
	return (dup);
}

char	*save_rest(char *buf)
{
	int		i;
	char	*rest;

	i = 0;
	while (buf[i] && buf[i] != '\n')
		i++;
	if (!buf[i])
	{
		free(buf);
		return ((void *)0);
	}
	rest = ft_strdup(buf + i + (buf[i] == '\n'));
	free(buf);
	return (rest);
}

char	*extract_line(char *buf)
{
	int i;
	char *line;

	i = 0;
	if (!buf || !buf[0])
		return ((void *)0);
	while (buf[i] && buf[i] != '\n')
		i++;
	if (buf[i] == '\n')
		i++;
	line = ft_substr(buf, 0, i);
	return (line);
}

char	*read_line(int fd, char *buf)
{
	char	tmp[BUFFER_SIZE + 1];
	ssize_t	r;
	char	*joined;

	if (!buf)
		buf = ft_strdup("");
	if (!buf)
		return ((void *)0);
	while (!ft_strchr(buf, '\n'))
	{
		r = read(fd, tmp, BUFFER_SIZE);
		printf("\nr:%zu\nbuf:%s\n",r,buf);
		if (r <= 0)
			break;
		tmp[r] = 0;
		joined = ft_strjoin(buf, tmp);
		if (!joined)
		{
			free(buf);
			return ((void *)0);
		}
		buf = joined;
	}
	return (buf);
}

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
