/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mecetink <mecetink@42student.kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 23:53:12 by mecetink          #+#    #+#             */
/*   Updated: 2025/06/25 00:04:58 by mecetink         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * Locates the first occurrence of the substring 'tofind' in the string 'str',
 * searching only within the first 'len' characters of 'str'.
 * @param str The string to search in.
 * @param tofind The substring to search for.
 * @param len The maximum number of characters to search in 'str'.
 * @return A pointer to the first occurrence of 'tofind' in 'str',
 * -or NULL if 'tofind' is not found within the first 'len' characters of 'str'.
 * @return If 'tofind' is an empty string, it returns a pointer to 'str'.
 * @return If 'len' is 0, it returns NULL.
 * ? Example:
 * * ft_strnstr("Hello, World!", "World", 13) returns a pointer to the 'W' in "World!".
 */

#include <stddef.h>

char	*ft_strnstr(const char *str, const char *tofind, size_t len)
{
	size_t	i;
	size_t	j;

	if (*tofind == 0)
		return ((char *)str);
	i = 0;
	while (str[i] != 0 && i < len)
	{
		if (str[i] == tofind[0])
		{
			j = 0;
			while (str[i + j]
				&& (i + j) < len && str[i + j] == tofind[j])
				j++;
			if (tofind[j] == 0)
				return ((char *)&str[i]);
		}
		i++;
	}
	return ((void *)0);
}
