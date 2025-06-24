/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mecetink <mecetink@42student.kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 16:47:10 by mecetink          #+#    #+#             */
/*   Updated: 2025/06/24 17:56:40 by mecetink         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * Copies up to 'size - 1' characters from the string 'src' to 'dst',
 * null-terminating the result. If 'size' is 0, it does not copy anything
 * and returns the length of 'src'.
 * @param dst The destination string where 'src' will be copied.
 * @param src The source string to copy from.
 * @param size The size of the destination buffer, including space for the null terminator.
 * @return The length of 'src', which is the total number of characters in 'src
 * -(excluding the null terminator).
 * @return If 'size' is 0, it returns the length of 'src'.
 * @return If 'dst' is NULL, it returns the length of 'src'.
 * @return The resulting string in 'dst' is always null-terminated.
 */

#include <stddef.h>

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	srclen;
	size_t	i;

	i = 0;
	srclen = 0;
	while (src[srclen])
		srclen++;
	if (size == 0)
		return (srclen);
	while (src[i] && i < size - 1)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = 0;
	return (srclen);
}
