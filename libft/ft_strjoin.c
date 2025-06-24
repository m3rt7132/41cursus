/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mecetink <mecetink@42student.kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 16:07:04 by mecetink          #+#    #+#             */
/*   Updated: 2025/06/24 17:54:33 by mecetink         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * Concatenates two strings into a new dynamically allocated string.
 * The new string is the result of joining 's1' and 's2'.
 * If either 's1' or 's2' is NULL, it returns NULL.
 * @param s1 The first string to concatenate.
 * @param s2 The second string to concatenate.
 * @return A pointer to the newly allocated string containing the concatenation,
 * @return or NULL if memory allocation fails.
 * ? Example:
 * * ft_strjoin("Hello, ", "World!") returns "Hello, World!".
 */

#include "libft.h"
#include <stdlib.h>

char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*newstr;
	int		s1len;
	int		s2len;
	int		i;

	i = 0;
	s1len = ft_strlen(s1);
	s2len = ft_strlen(s2);
	newstr = (char *) malloc(sizeof(char) * (s1len + s2len + 1));
	if (!newstr)
		return ((void *)0);
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
