#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	const char	*start;

	start = s;
	while (*s)
		s++;
	return (s - start);
}

char	*ft_strjoin(char *s1, const char *s2)
{
	char	*newstr;
	size_t	s1len;
	size_t	s2len;
	size_t	i;

	i = 0;
	s1len = ft_strlen(s1);
	s2len = ft_strlen(s2);
	newstr = (char *) malloc(sizeof(char) * (s1len + s2len + 1));
	if (!newstr)
		return (NULL);
	while (*s1)
	{
		newstr[i] = *s1;
		s1++;
		i++;
	}
	while (*s2)
	{
		newstr[i] = *s2;
		s2++;
		i++;
	}
	newstr[i] = 0;
	return (newstr);
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
		len = ft_strlen(s) - start;
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
	size_t	tozero;

	tozero = nmemb * size;
	alloc = malloc(tozero);
	if (alloc == NULL)
		return ((void *)0);
	while (tozero)
	{
		*(((unsigned char *)alloc) + tozero) = 0;
		tozero--;
	}
	*((unsigned char *)alloc + 0) = 0;
	return (alloc);
}
