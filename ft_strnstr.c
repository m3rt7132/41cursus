/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mecetink <mecetink@42student.kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 23:53:12 by mecetink          #+#    #+#             */
/*   Updated: 2025/06/01 00:48:40 by mecetink         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	if (*little == 0)
		return ((char *)big);
	i = 0;
	while (big[i] != 0 && i < len)
	{
		if (big[i] == little[0])
		{
			j = 0;
			while (little[j] && big[i + j] && (i + j) < len && big[i + j] == little[j])
				j++;
			if (little[j] == 0)
				return ((char *)&big[i]);
		}
		i++;
	}	
	return (NULL);
}