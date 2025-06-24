/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mecetink <mecetink@42student.kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/01 20:15:30 by mecetink          #+#    #+#             */
/*   Updated: 2025/06/24 17:37:33 by mecetink         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * Searches for the first occurrence of a character in a block of memory.
 * @param s Pointer to the block of memory to search.
 * @param c The character to search for.
 * @param n The number of bytes to search.
 * @return A pointer to the first occurrence of the character in the block of memory,
 * @return or NULL if the character is not found within the specified number of bytes.
 * * This function is useful for searching through binary data or strings.
 */

#include <stddef.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char		*usrc;
	unsigned char		uchar;

	usrc = (unsigned char *)s;
	uchar = (unsigned char)c;
	while (n--)
	{
		if (*usrc == uchar)
			return ((void *)usrc);
		usrc++;
	}
	return ((void *)0);
}
