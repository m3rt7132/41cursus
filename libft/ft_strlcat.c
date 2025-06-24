/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mecetink <mecetink@42student.kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 12:42:05 by mecetink          #+#    #+#             */
/*   Updated: 2025/06/25 00:00:03 by mecetink         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * Appends the string 'src' to the end of 'dst', ensuring that the total length
 * of the resulting string does not exceed 'size - 1'. It always null-terminates
 * the resulting string, and returns the total length of the string it tried to create.
 * If 'dst' is already longer than or equal to 'size', it returns 'size + srclen',
 * where 'srclen' is the length of 'src' (man strlcat).
 * @param dst The destination string to which 'src' will be appended.
 * @param src The source string to append to 'dst'.
 * @param size The size of the destination buffer, including space for the null terminator
 * @return The total length of the string it tried to create, which is the length of 'dst'
 * -plus the length of 'src'. If 'dst' is already longer than or equal to 'size',
 * -it returns 'size + srclen', where 'srclen' is the length of 'src'.
 * @return The resulting string is always null-terminated.
 */

#include <stddef.h>

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	srclen;
	size_t	cpylen;
	size_t	dstlen;

	i = 0;
	srclen = 0;
	dstlen = 0;
	while (src[srclen])
		srclen++;
	while (dst[dstlen])
		dstlen++;
	if (dstlen >= size)
		return (size + srclen);
	cpylen = size - dstlen - 1;
	while (src[i] && i < cpylen)
	{
		dst[dstlen + i] = src[i];
		i++;
	}
	dst[dstlen + i] = 0;
	return (dstlen + srclen);
}
