#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	const char	*start;

	start = s;
	while (*s)
		s++;
	return (s - start);
}

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*cast;
	unsigned char	val;

	cast = (unsigned char *)s;
	val = (unsigned char)c;
	while (n--)
		*cast++ = val;
	return (s);
}

char	*ft_strjoin(char *s1, const char *s2)
{
	size_t	len1 = ft_strlen(s1), len2 = ft_strlen(s2), i = 0, j = 0;
    char	*res = malloc(len1 + len2 + 1);
    if (!res)
    {
        free(s1); // Bellek sızıntısını önle
        return (NULL);
    }
    while (s1 && s1[i])
        { res[i] = s1[i]; i++; }
    while (s2 && s2[j])
        res[i++] = s2[j++];
    res[i] = 0;
    free(s1);
    return (res);
}

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	char	*copy;
	size_t	i;

	if (start >= (unsigned int)ft_strlen(s))
	{
		copy = (char *) malloc(sizeof(char));
		if (!copy)
			return ((void *)0);
		copy[0] = 0;
		return (copy);
	}
	if (len > ft_strlen(s) - start)
		len = ft_strlen(s) - start; // Adjust length if it exceeds the remaining string length
	copy = (char *) malloc(sizeof(char) * (len + 1));
	if (!copy)
		return ((void *)0);
	s = s + start;
	i = 0;
	while (i < len && s[i])
	{
		copy[i] = s[i];
		i++;
	}
	copy[i] = 0;
	return (copy);
}

char	*ft_strchr(const char *s, int c)
{
	while (1)
	{
		if (*s == (char)c)
			return ((char *)s);
		if (*s == 0)
			break ;
		s++;
	}
	return ((void *)0);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*alloc;

	if (nmemb == 0 || size == 0)
	{
		alloc = malloc(0);
		if (alloc == NULL)
			return ((void *)0);
		return (alloc);
	}
	alloc = malloc(nmemb * size);
	if (alloc == NULL)
	return ((void *)0);
	ft_memset(alloc, 0, nmemb * size);
	return (alloc);
}

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
	int		r;
	char	*joined;

	if (!buf)
		buf = ft_strdup("");
	if (!buf)
		return ((void *)0);
	while (!ft_strchr(buf, '\n'))
	{
		r = read(fd, tmp, BUFFER_SIZE);
		if (r <= 0)
			break;
		tmp[r] = 0;
		joined = ft_strjoin(buf, tmp);
		if (!joined)
		{
			free(buf);
			buf = NULL;
			return ((void *)0);
		}
		buf = joined;
	}
	return (buf);
}
