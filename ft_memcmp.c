/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mecetink <mecetink@42student.kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 17:43:51 by mecetink          #+#    #+#             */
/*   Updated: 2025/06/03 20:39:31 by mecetink         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*m1;
	unsigned char	*m2;
	size_t			i;

	if (n == 0)
		return (0);
	i = 0;
	m1 = (unsigned char *)s1;
	m2 = (unsigned char *)s2;
	while (i < n && m1[i] == m2[i])
		i++;
	return (m1[i] - m2[i]);
}
