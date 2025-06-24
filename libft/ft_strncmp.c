/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mecetink <mecetink@42student.kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 17:40:59 by mecetink          #+#    #+#             */
/*   Updated: 2025/06/25 00:02:47 by mecetink         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * Compares the first 'n' characters of two strings.
 * It compares the characters of 's1' and 's2' up to 'n' characters or until a null
 * terminator is encountered in either string.
 * @param s1 The first string to compare.
 * @param s2 The second string to compare.
 * @param n The maximum number of characters to compare.
 * @return An integer less than, equal to, or greater than zero if 's1' is found,
 * -to be less than, to match, or be greater than 's2', respectively.
 * @return If 'n' is zero, the function returns 0, indicating that the strings are equal
 * -up to the specified length.
 * @return If the strings differ before reaching 'n' characters, the function returns the
 * -difference between the first differing characters (as unsigned char).
 * @return If both strings are equal up to 'n' characters, the function returns 0.
 * ! The function treats the strings as arrays of unsigned char, so it can handle
 * ! characters with values greater than 127 correctly.
 */

#include <stddef.h>

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if ((unsigned char)s1[i] != (unsigned char)s2[i] || !s1[i] || !s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return (0);
}
