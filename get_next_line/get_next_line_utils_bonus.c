/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mecetink <mecetink@42student.kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/29 18:13:25 by mecetink          #+#    #+#             */
/*   Updated: 2025/06/29 20:32:01 by mecetink         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(const char *s)
{
	const char	*start;

	start = s;
	while (*s)
		s++;
	return (s - start);
}

char	*ft_strdup(const char *s)
{
	size_t	len;
	size_t	i;
	char	*dup;

	len = ft_strlen(s);
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

char	*ft_strjoin(char *s1, const char *s2)
{
	char	*newstr;
	size_t	i;
	size_t	j;

	i = 0;
	newstr = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) +1));
	if (!newstr)
		return ((void *)0);
	while (s1[i])
	{
		newstr[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
		newstr[i++] = s2[j++];
	free(s1);
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
