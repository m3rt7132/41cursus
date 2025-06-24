/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mecetink <mecetink@42student.kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 15:16:33 by mecetink          #+#    #+#             */
/*   Updated: 2025/06/24 17:41:57 by mecetink         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * Copies 'n' bytes from the source memory area to the destination memory area,
 * handling overlapping memory areas correctly.
 * If the source and destination overlap, the function ensures that the data is
 * copied correctly without corruption.
 * @param dest Pointer to the destination memory area.
 * @param src Pointer to the source memory area.
 * @param n The number of bytes to copy.
 * @return Pointer to the destination memory area.
 * @return If 'dest' or 'src' is NULL, it returns NULL.
 * ! Note: The destination memory area must be large enough to hold 'n' bytes.
 * ! If 'n' is zero, the function does nothing and returns 'dest'.
 * ! This function is useful for safely moving memory blocks that may overlap.
 * ! If you need to copy memory areas that do not overlap, consider using `ft_memcpy`.
 * * If the source is less than the destination, it copies from the beginning to the end.
 * * If the source is greater than the destination, it copies from the end to the beginning.
 * * This function is useful for safely moving memory blocks that may overlap.
 */

#include <stddef.h>
#include <stdlib.h>

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t	i;

	i = 0;
	if (!dest && !src)
		return ((void *)0);
	if (dest == src)
		return (dest);
	if (dest < src)
	{
		while (i < n)
		{
			((char *) dest)[i] = ((char *) src)[i];
			i++;
		}
	}
	else
	{
		while (n--)
			((char *) dest)[n] = ((char *) src)[n];
	}
	return (dest);
}
