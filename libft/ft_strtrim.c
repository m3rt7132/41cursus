/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mecetink <mecetink@42student.kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 16:44:07 by mecetink          #+#    #+#             */
/*   Updated: 2025/06/25 00:09:40 by mecetink         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * Trims leading and trailing characters from a string.
 * This function removes all characters from the beginning and end of the string
 * that are present in the 'set' string.
 * @param s1 The string to be trimmed.
 * @param set The set of characters to be removed from the beginning and end of 's1'.
 * @return A new dynamically allocated string with the trimmed result,
 * -or NULL if memory allocation fails.
 * @return If 's1' is NULL or 'set' is NULL, it returns NULL.
 * @return If 's1' is an empty string, it returns a new empty string that
 * -needs to be freed by the caller.
 * ? Example:
 * * ft_strtrim("  Hello, World!  ", " ") returns "Hello, World!".
 * * ft_strtrim("Hello, World!", "Helo, Wrd!") returns " !".
 * * ft_strtrim("abchelloabc", "bc") returns "abchelloa"
 */

#include "libft.h"
#include <stdlib.h>

char	*ft_strtrim(const char *s1, const char *set)
{
	size_t	srclength;
	size_t	start;
	char	*newstr;

	if (s1 == NULL || set == NULL)
		return ((void *)0);
	if (*s1 == 0)
	{
		newstr = ft_strdup("");
		if (!newstr)
			return ((void *)0);
		return (newstr);
	}
	srclength = ft_strlen(s1);
	start = 0;
	while (s1[start] && ft_strchr(set, s1[start]))
		start++;
	while (srclength > start && ft_strchr(set, s1[srclength - 1]))
		srclength--;
	newstr = (char *) malloc(sizeof(char) * (srclength - start + 1));
	if (!newstr)
		return ((void *)0);
	ft_memcpy(newstr, s1 + start, srclength - start);
	newstr[srclength - start] = 0;
	return (newstr);
}
