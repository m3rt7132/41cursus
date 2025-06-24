/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mecetink <mecetink@42student.kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 13:16:28 by mecetink          #+#    #+#             */
/*   Updated: 2025/06/24 17:39:55 by mecetink         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * Copies 'n' bytes from the source memory area to the destination memory area.
 * If the source and destination overlap, the behavior is undefined.
 * @param dest Pointer to the destination memory area.
 * @param src Pointer to the source memory area.
 * @param n The number of bytes to copy.
 * @return Pointer to the destination memory area.
 * @return If 'dest' or 'src' is NULL, it returns NULL.
 * ! Note: The destination memory area must be large enough to hold 'n' bytes.
 * ! If 'n' is zero, the function does nothing and returns 'dest'.
 * ! Memory areas must not overlap, otherwise the behavior is undefined.
 * ! If overlap occurs, use `ft_memmove` instead. (man memcpy)
 */

#include <stddef.h>

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t		i;
	char		*d;
	const char	*s;

	i = 0;
	if (!dest && !src)
		return ((void *)0);
	d = (char *) dest;
	s = (const char *) src;
	while (i < n)
	{
		d[i] = s[i];
		i++;
	}
	return (dest);
}
