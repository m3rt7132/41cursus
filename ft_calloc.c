/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mecetink <mecetink@42student.kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/01 20:36:43 by mecetink          #+#    #+#             */
/*   Updated: 2025/06/04 16:52:28 by mecetink         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*alloc;

	if (nmemb == 0 || size == 0)
		return (malloc(sizeof(char)));
	if (nmemb != 0 && nmemb > 18446744073709551615UL / size)
		return (0);
	alloc = malloc(nmemb * size);
	if (alloc == NULL)
		return (NULL);
	ft_memset(alloc, 0, nmemb * size);
	return (alloc);
}
