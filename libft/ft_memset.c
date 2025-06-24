/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mecetink <mecetink@42student.kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 17:47:22 by mecetink          #+#    #+#             */
/*   Updated: 2025/06/24 17:43:23 by mecetink         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * Sets the first 'n' bytes of the memory area pointed to by 's' to the value of 'c'.
 * @param s Pointer to the memory area to be set.
 * @param c The value to set the bytes to.
 * @param n The number of bytes to set.
 * @return Pointer to the memory area 's'.
 * * This function is useful for initializing memory to a specific value.
 * * For example, you can use it to set a buffer to zero or to a specific
 * * character value before using it.
 */

#include <stddef.h>

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*cast;
	unsigned char	val;

	cast = (unsigned char *)s;
	val = (unsigned char)c;
	while (n--)
		*cast++ = val;
	return (s);
}
