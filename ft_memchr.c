/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mecetink <mecetink@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/01 20:15:30 by mecetink          #+#    #+#             */
/*   Updated: 2025/06/02 18:04:22 by mecetink         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*usrc;
	unsigned char		uchar;

	usrc = s;
	uchar = (unsigned char)c;
	while (n--)
	{
		if (*usrc == uchar)
			return ((void *)usrc);
		usrc++;
	}
	return (NULL);
}
