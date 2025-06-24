/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mecetink <mecetink@42student.kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 12:21:55 by mecetink          #+#    #+#             */
/*   Updated: 2025/06/25 00:06:47 by mecetink         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * Locates the last occurrence of a character in a string.
 * This function searches for the last occurrence of the character 'c'
 * in the string 's'.
 * This is reverse of the 'strchr' function.
 * @param s The string to search in.
 * @param c The character to search for.
 * @return A pointer to the last occurrence of 'c' in 's',
 * -or NULL if 'c' is not found in 's'.
 * @return If 'c' is the null terminator ('\0'), it returns a pointer
 * -to the null terminator at the end of the string.
 * ? Example:
 * * ft_strrchr("Hello, World!", 'o') returns a pointer to the last 'o' in "World!".
 */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	const char	*f;

	f = s + ft_strlen(s);
	while (f >= s)
	{
		if (*f == (char)c)
			return ((char *)f);
		f--;
	}
	return ((void *)0);
}
