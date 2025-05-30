/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mecetink <mecetink@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 17:47:22 by mecetink          #+#    #+#             */
/*   Updated: 2025/05/30 15:12:32 by mecetink         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*cast;
	unsigned char	val;

	cast = (unsigned char *)s;
	val = (unsigned char)c;
	while (n-- > 0)
		*cast++ = val;
	return (s);
}
