/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mecetink <mecetink@42student.kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 23:53:12 by mecetink          #+#    #+#             */
/*   Updated: 2025/06/05 01:25:13 by mecetink         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

char	*ft_strnstr(const char *str, const char *tofind, size_t len)
{
	size_t	i;
	size_t	j;

	if (*tofind == 0)
		return ((char *)str);
	i = 0;
	while (str[i] != 0 && i < len)
	{
		if (str[i] == tofind[0])
		{
			j = 0;
			while (tofind[j] && str[i + j]
				&& (i + j) < len && str[i + j] == tofind[j])
				j++;
			if (tofind[j] == 0)
				return ((char *)&str[i]);
		}
		i++;
	}
	return (NULL);
}
