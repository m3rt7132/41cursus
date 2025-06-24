/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mecetink <mecetink@42student.kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/01 20:36:43 by mecetink          #+#    #+#             */
/*   Updated: 2025/06/24 23:47:35 by mecetink         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * Allocates memory for an array of 'nmemb' elements, each of size 'size',
 * and initializes all bytes to zero.
 * @param nmemb Number of elements to allocate.
 * @param size Size of each element in bytes.
 * @return Pointer to the allocated memory, or NULL if the allocation fails.
 * @return If 'nmemb' or 'size' is zero, it returns a pointer
 * to a zero-sized memory block. (By PDF)
 */

#include "libft.h"
#include <stdlib.h>

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*alloc;

	if (nmemb == 0 || size == 0)
	{
		alloc = malloc(0);
		if (alloc == NULL)
			return ((void *)0);
		return (alloc);
	}
	alloc = malloc(nmemb * size);
	if (alloc == NULL)
		return ((void *)0);
	ft_bzero(alloc, nmemb * size);
	return (alloc);
}
